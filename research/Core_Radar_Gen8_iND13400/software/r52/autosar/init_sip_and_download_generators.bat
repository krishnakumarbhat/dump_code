cd ../../..
call git submodule update --init --progress -- software/r52/autosar/sip
python .\software\r52\autosar\sip\tools\python\toolsInit\toolsInit.py --sip_generators
