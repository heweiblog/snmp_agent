TGT=yamu_snmp_agent

all:$(TGT)
	@echo Generation target!	
	cp $(TGT) ../


$(TGT):
	net-snmp-config --compile-subagent $(TGT) ./*.c
