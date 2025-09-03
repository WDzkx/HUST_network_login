# 华科校园网自动登录脚本————解决使用网线不能自动连接的不便
最终可实现电脑开机自动连接校园以太网(即"无感认证")
# 指南
1.确保电脑有Python运行环境或者C++运行环境
2.连接网线
2.获取加密密码和设备静态校验码
  如果电脑已登录校园网请在校园网自助服务系统网页(http://myself.hust.edu.cn:8080/selfservice/)将此设备"下线"
  打开浏览器或任意网页，会自动跳转到校园网认证界面，按F12进入检查窗口以捕获网页请求；
  输入校园网帐号密码，点击"连接"登录校园网；
  <img width="1552" height="924" alt="HUST校园网认证界面" src="https://github.com/user-attachments/assets/d40d7396-ea97-425e-9200-e917c9ada3cc" />
  回到检查窗口，依次进入"网络"->"InterFace.do?method=login"->"负载"->"表单数据"，获得加密密码(password)和校验码(queryString)
  <img width="1518" height="1141" alt="获取表单数据" src="https://github.com/user-attachments/assets/65930177-1e38-47df-b364-43e64fbaf314" />
3.在代码中填充请求数据
  在Python脚本('AutoLink.py')或者C++脚本('AutoLink.cpp')中设置请求数据的部分填充用户名、加密密码、校验码
4.编译封装为可执行文件(以windows为例)
  A.(推荐)使用C++编译
  安装cURL库(https://curl.se/windows/)并将其配置到环境中重试重试
  在命令行中使用以下命令将C++脚本AutoLink.cpp编译成.exe文件:
    g++ -o AutoLink.exe AutoLink.cpp -mwindows -lcurl
  B.使用Python编译
  安装PyInstaller库:
    pip install pyinstaller
  在命令行中使用以下命令将Python脚本AutoLink.py编译成.exe文件:
    pyinstaller --onefile AutoLink.py
5.运行可执行文件'AutoLink.exe'即可实现自动连接校园网
  A.将程序放至桌面，开机后双击运行即可连接校园网
  B.(推荐)将程序放至合适目录，设置开机自启(以windows为例)
    使用系统开始菜单搜索"任务计划程序"，然后按以下步骤操作：
    <img width="1157" height="715" alt="打开任务计划程序新建任务计划" src="https://github.com/user-attachments/assets/21ad74ea-5b68-42ad-bbe9-50f3d8ef13f8" />
    <img width="1043" height="823" alt="1" src="https://github.com/user-attachments/assets/e3049b05-39bd-446e-b7d4-0161cb8348c7" />
    <img width="1043" height="823" alt="2" src="https://github.com/user-attachments/assets/6cb4c7d3-cd74-4e11-8278-d3f979b50ede" />重试重试
    <img width="1043" height="823" alt="3" src="https://github.com/user-attachments/assets/88563e75-6624-4e48-b5b3-07c3f141214c" />
    <img width="1043" height="823" alt="4" src="https://github.com/user-attachments/assets/e45ceb64-1e36-4bb2-88e6-c32173632b8e" />
    <img width="947" height="810" alt="5" src="https://github.com/user-attachments/assets/478c03ba-3bdc-40c7-8100-7d75162e46cb" />
    <img width="947" height="810" alt="6" src="https://github.com/user-attachments/assets/ae0efb9c-a216-49ad-a963-8e76151288f7" />
    <img width="947" height="810" alt="7" src="https://github.com/user-attachments/assets/1ecc10dd-0749-44e2-9c50-961f116de7b3" />
    大功告成！每次开机或唤醒将自动连接校园以太网！


