// Run: node ALL_KPI/tests/test_hyperlink_viewer_add.cjs
const assert = require('node:assert/strict');
const fs = require('node:fs');
const vm = require('node:vm');
const path = require('node:path');
const source = fs.readFileSync(path.join(__dirname, '../Hyperlink_tool/code/html_online/static/js/viewer.js'), 'utf8');
const elements = new Map();
function element(id) {
  if (!elements.has(id)) elements.set(id, { value: '', querySelector: () => null });
  return elements.get(id);
}
let calls = [], rendered = [], notifications = [];
const context = vm.createContext({
  console, AbortController, setTimeout, clearTimeout,
  window: { location: { pathname: '/hyperlink/' } },
  document: { addEventListener() {}, getElementById: element },
  fetch: async (url) => { calls.push(url); return { ok: true, json: async () => ({ success: true, saved_id: 42, entry: { saved_id: 42, video_name: 'sample.mp4' } }) }; },
});
vm.runInContext(source, context);
context.renderSavedList = () => { rendered = JSON.parse(vm.runInContext('JSON.stringify(mappings)', context)); };
for (const name of ['displayRemoteLogs', 'setSavedRailOpen', 'showLoading', 'hideLoading', 'closeClusterModal']) context[name] = () => {};
context.showNotification = context.showClusterMessage = (message) => notifications.push(message);
context.updateScenario = async () => {};
(async () => {
  vm.runInContext("remoteLogs.test = { video_path: '/remote/sample.mp4', html_missing: true };", context);
  element('savedSearchInput').value = 'unrelated search';
  await context.downloadLog('test');
  assert.equal(calls.length, 1, 'Add must not trigger full mapping scan');
  assert.equal(rendered['42'].saved_id, 42);
  assert.equal(element('savedSearchInput').value, '');
  assert.equal(vm.runInContext('remoteLogs.test.saved', context), true);
  context.fetch = async () => ({ ok: false, status: 500, json: async () => ({ success: false, error: 'offline' }) });
  await assert.rejects(context.loadMappings(), /offline/);
  assert.equal(vm.runInContext('mappings[42].saved_id', context), 42, 'Failed refresh must retain saved items');
  let resolve;
  context.fetch = () => new Promise(r => { resolve = r; });
  const pending = context.loadMappings();
  vm.runInContext('++mappingRevision; mappings[43] = {saved_id: 43};', context);
  resolve({ ok: true, json: async () => ({ success: true, mappings: {} }) });
  await pending;
  assert.equal(vm.runInContext('mappings[43].saved_id', context), 43, 'Stale refresh must not erase new add');
  context.fetch = async () => ({ ok: true, json: async () => ({ success: true }) });
  vm.runInContext("remoteLogs.failed = {video_path: '/remote/failed.mp4', html_missing: true};", context);
  await context.downloadLog('failed');
  assert.equal(vm.runInContext('Boolean(remoteLogs.failed.saved)', context), false, 'No saved id must not produce Added');
  assert.ok(notifications.some(message => message.includes('not saved')));
  console.log('Hyperlink viewer add regression checks passed');
})().catch(error => { console.error(error); process.exitCode = 1; });
