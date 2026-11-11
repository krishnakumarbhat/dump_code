@echo off
cd ../../../
set directory=%1
del %directory%\SRR8*.dll /f
del %directory%\SRR8*.a /f
del %directory%\FLR8*.dll /f
del %directory%\FLR8*.a /f
copy bazel-bin\sil\emb_lib\sil_source\emb_lib_sharedlib.dll %directory%\SRR8_SiL_FL.dll
copy bazel-bin\sil\emb_lib\sil_source\emb_lib_sharedlib.dll %directory%\SRR8_SiL_FR.dll
copy bazel-bin\sil\emb_lib\sil_source\emb_lib_sharedlib.dll %directory%\SRR8_SiL_RL.dll
copy bazel-bin\sil\emb_lib\sil_source\emb_lib_sharedlib.dll %directory%\SRR8_SiL_RR.dll
copy bazel-bin\sil\emb_lib\sil_source\emb_lib_sharedlib.dll %directory%\FLR8_SIL_FC.dll
copy bazel-bin\sil\emb_lib\sil_source\emb_lib_shared.a %directory%\SRR8_SiL_FL.a
copy bazel-bin\sil\emb_lib\sil_source\emb_lib_shared.a %directory%\SRR8_SiL_FR.a
copy bazel-bin\sil\emb_lib\sil_source\emb_lib_shared.a %directory%\SRR8_SiL_RL.a
copy bazel-bin\sil\emb_lib\sil_source\emb_lib_shared.a %directory%\SRR8_SiL_RR.a
copy bazel-bin\sil\emb_lib\sil_source\emb_lib_shared.a %directory%\FLR8_SIL_FC.a
echo Copied at %time:~0,8%
cd sil/emb_lib/build_bin
