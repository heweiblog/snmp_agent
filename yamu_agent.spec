Name: yamu_agent		
Version: 1.0.0
Release: 1%{dist}
Summary: YAMU yamu_agent

Group: Applications/Internet
License: GPL
URL: http://www.yamutech.com
Source0: yamu_agent-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}

%description
YAMU yamu_agent


%prep
%setup -q -n yamu_agent-%{version}


%build
#make %{?_smp_mflags}
make

%install
rm -rf %{buildroot}
mkdir -p %{buildroot}/%{_bindir}
mkdir -p %{buildroot}/etc/
mkdir -p %{buildroot}/etc/init.d/

install -m 755 yamu_agent %{buildroot}/%{_bindir}/yamu_agent
install -m 755 config/yamu_agentd  %{buildroot}/etc/init.d/

%clean
rm -rf %{buildroot}

%post
chkconfig --add yamu_agentd

%files
%defattr(-,root,root,-)
%{_bindir}/yamu_agent
/etc/init.d/yamu_agentd

%preun
chkconfig --del yamu_agentd

%changelog

