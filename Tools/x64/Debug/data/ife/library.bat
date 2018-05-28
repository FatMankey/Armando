rem cd C:\Program Files (x86)\Microsoft Visual Studio\2017\Community
call %comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat"	

cd\c:\data\ife

lib /libpath:/Libs /out:ife.lib tools.lib ife-original.lib
pause