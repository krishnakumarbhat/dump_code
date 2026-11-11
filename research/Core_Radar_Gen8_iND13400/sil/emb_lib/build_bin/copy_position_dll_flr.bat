@echo off
cd ../../../
set directory=%1
del %directory%\FLR8*.dll /f
del %directory%\FLR8*.a /f
copy bazel-bin\sil\emb_lib\sil_source\emb_lib_sharedlib.dll %directory%\FLR8_SIL_FC.dll
copy bazel-bin\sil\emb_lib\sil_source\emb_lib_sharedlib.dll %directory%\FLR8_SIL_FC.a
echo Copied at %time:~0,8%
cd sil/emb_lib/build_bin
