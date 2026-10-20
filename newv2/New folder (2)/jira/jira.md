Manage Jira updates for the HZP board using my local repo:

Repo:
C:\Users\ouymc2\Desktop\core-resim-kpi

Jira:
- URL: https://jiraprod.aptiv.com
- Project: HZP
- Board ID: 14936
- Use Jira credentials from environment variables. Never expose credentials/tokens.

Before updating Jira:
1. Inspect the repo using git status, git log, git diff, branches, and relevant .md files.
2. Understand which code changes belong to which HZP tickets.
3. Never move a ticket to Done unless the corresponding Git commit ID exists.
4. When moving a ticket to Done, add the relevant commit ID in a Jira comment.

When I say "update all Jira":
- Only modify tickets in the HZP project/board.
- Update ticket descriptions/comments based on the actual repo changes.
- Move completed tickets to Done.
- Move HZP-888 to In Review because it is still under review.
- Delete obvious test tickets identified by titles/descriptions such as "job #<number>".
- Do not touch tickets outside HZP.

Ticket creation:
- New Jira tickets must be children of CXY-1908 only for Adhoc tasks.
- All other new tickets must be children of CXY-1833.

Privacy:
- Never include credentials, tokens, private/sensitive information, or unnecessary internal data in Jira descriptions or comments.

Be concise, verify everything from Git before making Jira changes, and perform the required updates directly.

and as much more detail in descption about the  detail as possbile 


# Required
JIRA_BASE_URL=https://jiraprod.aptiv.com
# SECURITY: keep the PAT in .env (JIRA_PAT=...), never in a tracked file.
# A PAT was previously committed here in plain text and was removed.
JIRA_PAT=<read from .env>

# Optional (for Jira Cloud/Basic auth mode)
# JIRA_USER=your.email@company.com
# JIRA_API_TOKEN=replace_with_api_token

# Defaults for this board
JIRA_DEFAULT_PROJECT=HZP
JIRA_DEFAULT_BOARD_ID=14936

# Optional
# JIRA_VERIFY_SSL=true
# JIRA_TIMEOUT_SECONDS=30


for update see this proeprly : c:\Users\ouymc2\Desktop\core-resim-kpi hses is project repo stored you do git statua nd use git to see the things 
wihtout git commit id you cna't move any thing to done state 

don't share anything private in descption or while writing comment in jira ticket

when i give updae all jira in prompt then you need to see my repo udnerstand the cahnges and updte all the jira ticket and updte w.r.t all detail give here understand and do it properly \

and every jira tiket create for me should be chile of cxy 1908 is only adhoc task or else "CXY-1833" 

i want you to update everything hzp i pushed many chagessee changes and update descption also put all done to done and wip to inreview for hzp 888 as it is still in review and also delete all the test ticket you can see it like job # { it number } in ticket in hzp only touch hzp board more detail see .md also for done put commit id of git in comment do this fast use less tokens too 