### 使用net-snmp开发的子代理 本程序只是一个示例


### 子代理扩展
将生成的.c和.h文件编译成可执行程序，运行该程序和snmpd即可，优点是操作简单，缺点是需要运行两个程序才行。

### 开发步骤

1.编写MIB


2.生成.c和.h文件 

运行命令mib2c Test-SLK-MIB::Test 出现的选项依次选2和1.

3.链接


### 主代理启动

安装net-snmp 

snmpd --master=agentx  默认启动在后台


### 子代理启动
如果加入启动项 eg:service your agent start


### 可参考

https://www.jianshu.com/p/d1290258a42a

https://www.cnblogs.com/shenlinken/p/5316021.html
