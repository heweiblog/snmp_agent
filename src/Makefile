TGT=yamu_agent

all:$(TGT)
	@echo Generation target!	
	cp $(TGT) ../


$(TGT):
	net-snmp-config --compile-subagent $(TGT) ./*.c
