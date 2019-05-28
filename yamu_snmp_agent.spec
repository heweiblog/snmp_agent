Name: yamu_snmp_agent		
Version: @VERSION@
Release: @RELEASE@%{dist}
Summary: YAMU yamu_snmp_agent

Group: Applications/Internet
License: GPL
URL: http://www.yamutech.com
Source0: yamu_snmp_agent-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}

%description
YAMU yamu_snmp_agent


%prep
%setup -q -n yamu_snmp_agent-%{version}


%build
#make %{?_smp_mflags}
make

%install
rm -rf %{buildroot}
mkdir -p %{buildroot}/%{_bindir}
mkdir -p %{buildroot}/etc/
mkdir -p %{buildroot}/etc/init.d/

install -m 755 yamu_snmp_agent %{buildroot}/%{_bindir}/yamu_snmp_agent
install -m 755 config/yamu_snmp_agentd  %{buildroot}/etc/init.d/

%clean
rm -rf %{buildroot}

%post
if [ "$1" = "1" ]
then
	chkconfig --add yamu_snmp_agentd
fi



%files
%defattr(-,root,root,-)
%{_bindir}/yamu_snmp_agent
/etc/init.d/yamu_snmp_agentd

%preun
if [ "$1" = "0" ]
then
	chkconfig --del yamu_snmp_agentd
fi


%changelog

