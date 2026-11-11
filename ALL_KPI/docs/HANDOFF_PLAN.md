# Handoff Plan — ALL_KPI (all_services_8)

Repo: `C:\Users\ouymc2\Desktop\dump_code\ALL_KPI` (Flask `main_html` + broker `main_html/temp_dir/hpcc_main.py` + bundle scripts).
**Do NOT use `~/5008_core_kpi`**: it is a separate FastAPI rewrite that dropped Slurm, Jira, Hyperlink and Runtime Map. The user rejected it.

## Rules from the user
- Keep everything that already existed: Slurm, Jira tickets, Hyperlink, the runtime map (now labeled **"HPCC Pipeline Run"**), and the dashboard.
- Never hardcode a port or version number (for example `5008`) in filenames or UI text.
  - Set the port only in `hpcc_runtime.env` (`PORT=`).
  - Set deploy roots only in `.env` (`krakow_path`, `southfield_path`).
- Remove "Physical association gates" and any UI text such as "configure a local converter command…". Those come from the 5008 rewrite and must not be ported.
- MF4 support is an input mode: convert MF4 to HDF inside the job, then run KPI directly. Do not add a separate MUDP pipeline UI.
- Keep animations minimal so pages load fast.
- Keep the AI video description in Hyperlink available, but turn it off by default.
- Never print or commit `.env`, because it contains the cluster password.

## Already done (verify; do not redo)
1. **Per-user configs**: `main_html/kpi_config_manager.py`
   - Every function takes `net_id`.
   - Files live in `~/.hpcc_kpi_configs/<netid>/`, overridable with env `HPCC_KPI_CONFIG_ROOT`.
   - The first time a user opens a file, it is copied from `KPI/intplot_kpi/`.
   - `app.py` passes `current_user.net_id`.
   - Test: `tests/test_kpi_config_manager.py`.
   - `main_hpcc.sh` passes `HPCC_KPI_CONFIG_ROOT` into the container.
2. **Deploy settings**
   - `generate_upload.py` takes targets from `.env` `krakow_path` / `southfield_path`, falling back to `hpcc_runtime.env`.
   - `hpcc_runtime.env` is in `SCRIPTS` and the critical-files list.
   - Reload messages no longer mention a port.
   - `deploy` aborts if the WSL build is unavailable.
   - The `*_5008*` files were deleted.
   - `hpcc_runtime.env` now has `PORT=5008`, broker port `9208`, `all_services_8` roots, and empty `MUDP_SIMG` / `MUDP_CONFIG`.
3. **CAN KPI + CAN Interactive Plot fix**: `scripts/hpcc_bundle_templates/kpi/inplot_can.sh`
   - Starts the CAN KPI ZMQ server (`--app server`) before `--app plot`. Previously only the client ran, so it timed out.
   - With `--wait` (Slurm), it runs in the foreground with no tmux, because compute nodes may not have tmux.
4. **MF4 input modes** (`mf4` pair and `mf4_json`)
   - UI: radio buttons and labels in `templates/tools/kpi.html`.
   - Validation in `app.py`: `_validate_mf4_inputs`, accepted modes `{json, hdf, mf4, mf4_json}`.
   - Broker branch in `hpcc_main.py`: when `input_mode in {mf4, mf4_json}`, route through `kpi_runtime_launcher.sh`.
   - Launcher function `convert_mf4_inputs`:
     - Runs `singularity exec $MUDP_SIMG /RUN_MUDP.sh $MUDP_CONFIG list out/`, the same call as the MUDP pipeline.
     - Writes to `$OUTPUT_DIR/converted_hdf`.
     - Pairs `.h5` files by name stem (the `_rXXXX` suffix is stripped).
     - Then switches to JSON mode and runs normally.
5. **Hyperlink**
   - Posting the form now returns to `/html/hyperlink_tool`, which embeds the `/hyperlink/` viewer in an iframe (`viewer_active`, `html_root`).
   - The AI toggle text now says it is ready for later use.
6. Renamed the label "Runtime Map" to **"HPCC Pipeline Run"** in `base.html`, `dashboard.html`, `runtime_map.html` and `kpi.html`. Route names are unchanged.
7. Appended a CSS refresh to `main_html/static/css/style.css` (calm palette, `animation:none`, 0.12s transitions).
8. Created `KPI/intplot_kpi/big_script_report.py`, a Plotly version of the MATLAB "Big Script Report".
   - Reads HDF data and produces one combined plot per section with a Raw/Normalized toggle and a stream-health table.
   - Output goes to `<out>/big_script/`.
   - CLI: `python big_script_report.py <inputs.json> <out_dir>`.

## Remaining tasks (in order)
1. **Connect the big-script report.**
   - At the end of the `__main__` block in `KPI/intplot_kpi/ResimHTMLReport.py` and `KPI/can_interactive_plot/can_intplot_main.py`, after `asyncio.run(...)`, add:
     `from big_script_report import write_reports; write_reports(input_plot_json_file, output_directory or 'html')`
   - Copy the file to `KPI/can_interactive_plot/big_script_report.py`. Each image has its own source tree; a second copy is acceptable.
   - In the `%files` section of `KPI/intplot_kpi/singularity_interactiveplot.def`, add:
     `KPI/intplot_kpi/big_script_report.py /app/big_script_report.py`
   - In `KPI/can_interactive_plot/singularity_canintplot.def`, add:
     `KPI/can_interactive_plot/big_script_report.py /app/can_interactive_plot/big_script_report.py`
   - In `generate_upload.py`, the `SIMGG_SRC` entries already include those directories, so no change is needed.
   - Check locally:
     `python KPI/intplot_kpi/big_script_report.py <json with edge_hdf/udp/input/CCA_9010_3100099_DEBUG_20260119_120656_0001_r00080104.h5 + edge_hdf/udp/output/CCA_9010_3100099_DEBUG_20260119_120656_0001.h5> %TEMP%/bs`
   - The HTML must contain several `<section>` elements and open in a browser.
   - Reference: `C:\Users\ouymc2\Downloads\20260828_PAC1_Gen8_073419_R6p1p1_HighDetVar_PAC_Log1_Log19\*_Sensor_1_SRR8P.html`. Section names are listed in `SECTIONS`. Add regexes when HDF signal names do not match a section.
2. **Link the report from the interactive index.** In `KPI/*/InteractivePlot/e_presentation_layer/html_generator.py`, add a "Big Script Report" link to `big_script/index.html` on the master index. Keep this to one line of HTML and do not restructure the generator.
3. **Remove leftovers from the rewrite.**
   - Run: `rg -n -i "physical association|converter command|private HDF folder" ALL_KPI`.
   - Delete every hit from UI and templates. Leave algorithm code alone.
4. **Run tests.** From `ALL_KPI`, run:
   - `$env:PYTHONPATH='main_html;main_html/temp_dir;.'; python -m pytest -q tests`. Expect everything to pass; it was 123 before.
   - `cd KPI/can_interactive_plot; python -m pytest -q tests`. Expect 9 to pass.
   - `bash -n kpi_runtime_launcher.sh scripts/hpcc_bundle_templates/kpi/*.sh main_hpcc.sh`
   - Add one test in `tests/` for `_build_runtime_kpi_submission`:
     - MF4 mode rejects a non-`.mf4` file.
     - An unknown `input_mode` raises `ValueError`.
     - Use `app.test_request_context` and a logged-in user, or call the function after monkeypatching `current_user`.
5. **Review.** Run `git diff --check` and read `git diff` once to catch broken indentation in `app.py` edits. Look at the area around `_build_runtime_kpi_submission` and the `resource_target` line.
6. **Deploy.** Ask the user before running this.
   - From `ALL_KPI` on Windows: `python generate_upload.py deploy --no-rag`. This builds in WSL and uploads to both `.env` roots.
   - On each cluster: `cd <root>; bash run_hpcc.sh`.
   - Open `http://<host>:<PORT>/html/kpi`. Krakow is 10.214.45.45 and Southfield is 10.192.224.131.
7. **Smoke-test on both clusters.**
   - UDP KPI with an HDF pair.
   - CAN KPI with CAN Interactive Plot enabled, using `edge_hdf/can` pairs copied to the cluster.
   - Interactive Plot only. Check that `big_script/index.html` exists.
   - Hyperlink: load a report root and confirm the viewer appears inside `/html/hyperlink_tool`.
   - MF4 modes work only after the user sets `MUDP_SIMG` and `MUDP_CONFIG` in `hpcc_runtime.env`. The user will supply MF4 files and those paths later. Do not reuse paths from `MUDP_Pipeline/Config` that point to another user's files.

## Do not
- Rename Flask routes or endpoints, because templates use `url_for`.
- Touch the running 5007 deploy (`all_services_7`, broker 9207).
- Add new dependencies. h5py, numpy and plotly are already in both images.
