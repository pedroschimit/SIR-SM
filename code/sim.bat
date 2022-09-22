@echo off

FOR /L %%C IN (1,1,10) DO (
		
	FOR /L %%S IN (1,1,10) DO (
	
		SIR.exe --C %%C

	)

)	

pause