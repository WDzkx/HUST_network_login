# 华科校园网自动登录脚本

解决使用网线时不能自动连接的不便，最终可实现 **电脑开机自动连接校园以太网（即“无感认证”）**

---

## 使用指南

### 1. 准备工作

* 确保电脑具备 **Python** 或 **C++** 运行环境
* 连接网线

---

### 2. 获取加密密码和设备静态校验码

1. 如果电脑已登录校园网，请先在校园网自助服务系统 [http://myself.hust.edu.cn:8080/selfservice/](http://myself.hust.edu.cn:8080/selfservice/) 将此设备“下线”。
2. 打开浏览器，任意访问一个网页，会自动跳转到校园网认证界面。
3. 按 **F12** 打开检查窗口，切换到 **网络 (Network)**。
4. 输入校园网帐号密码，点击“连接”登录校园网。
5. 在请求中找到 `InterFace.do?method=login` → **负载 (Payload)** → **表单数据 (Form Data)**，即可获取：

   * `password`（加密密码）
   * `queryString`（设备校验码）

示例截图：

![HUST校园网认证界面](https://github.com/user-attachments/assets/d40d7396-ea97-425e-9200-e917c9ada3cc)
![获取表单数据](https://github.com/user-attachments/assets/65930177-1e38-47df-b364-43e64fbaf314)

---

### 3. 填充请求数据

在代码文件中填充以下信息：

* Python 脚本：`AutoLink.py`
* C++ 脚本：`AutoLink.cpp`

填写内容：用户名、加密密码、校验码。

---

### 4. 编译并封装为可执行文件（以 Windows 为例）

#### A. 推荐：使用 C++ 编译

1. 安装 [cURL 库](https://curl.se/windows/)，并配置到环境变量。
2. 使用以下命令编译：

   ```bash
   g++ -o AutoLink.exe AutoLink.cpp -mwindows -lcurl
   ```

#### B. 使用 Python 编译

1. 安装 **PyInstaller**：

   ```bash
   pip install pyinstaller
   ```
2. 执行编译：

   ```bash
   pyinstaller --onefile AutoLink.py
   ```

---

### 5. 运行可执行文件

* **方法 A**：将 `AutoLink.exe` 放在桌面，开机后双击运行即可。
* **方法 B（推荐）**：设置开机自启

  1. 将程序放至合适目录。
  2. 打开 **任务计划程序**，新建任务并添加启动项。

操作示例：
请将选项设置为与图中一致

![任务计划程序-新建任务](https://github.com/user-attachments/assets/21ad74ea-5b68-42ad-bbe9-50f3d8ef13f8)
![步骤1](https://github.com/user-attachments/assets/e3049b05-39bd-446e-b7d4-0161cb8348c7)
![步骤2](https://github.com/user-attachments/assets/6cb4c7d3-cd74-4e11-8278-d3f979b50ede)
![步骤3](https://github.com/user-attachments/assets/88563e75-6624-4e48-b5b3-07c3f141214c)
![步骤4](https://github.com/user-attachments/assets/e45ceb64-1e36-4bb2-88e6-c32173632b8e)
![步骤5](https://github.com/user-attachments/assets/478c03ba-3bdc-40c7-8100-7d75162e46cb)
![步骤6](https://github.com/user-attachments/assets/ae0efb9c-a216-49ad-a963-8e76151288f7)
![步骤7](https://github.com/user-attachments/assets/1ecc10dd-0749-44e2-9c50-961f116de7b3)

🎉 **大功告成！每次开机或唤醒将自动连接校园以太网！**
