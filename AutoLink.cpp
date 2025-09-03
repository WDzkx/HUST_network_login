#include <iostream>
#include <string>
#include <curl/curl.h>

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    
    // 初始化 cURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        // 设置目标 URL
        curl_easy_setopt(curl, CURLOPT_URL, "http://172.18.18.61:8080/eportal/InterFace.do?method=login");

    // 设置请求数据
      // 将userId中的example替换为自己的学号，例:U2023XXXXX
      // 将password中的example替换为自己的加密密码(需要在登录认证网页手动抓取)
      // 将queryString中的example替换为自己的校验码(需要在登录认证网页手动抓取)
      // 其他无需更改
    std::string data = "userId=example"      // 学号
                   "&password=example"       // 加密密码
                   "&service="
                   "&queryString=example"    // 校验码
                   "&operatorPwd="
                   "&operatorUserId="
                   "&validcode="
                   "&passwordEncrypt=true";


        // 设置 POST 请求
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

        // 设置请求头
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36");  // 模拟 Google Chrome 的 User-Agent
        headers = curl_slist_append(headers, "Accept-Encoding: gzip, deflate");  // 模拟 Accept-Encoding
        headers = curl_slist_append(headers, "Accept: */*");  // Accept 头
        headers = curl_slist_append(headers, "Connection: keep-alive");  // 保持连接
        headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded; charset=UTF-8");  // 设置请求内容类型

        // 传递请求头
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // 设置响应回调函数
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // 执行请求
        res = curl_easy_perform(curl);

        // 检查请求是否成功
        if(res != CURLE_OK) {
            std::cerr << "Request failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // 获取返回的 HTTP 状态码
            long http_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            std::cout << "HTTP Response Code: " << http_code << std::endl;

            // 打印返回的响应体
            std::cout << "Response Body: " << readBuffer << std::endl;
        }

        // 清理请求头
        curl_slist_free_all(headers);

        // 清理 cURL
        curl_easy_cleanup(curl);
    }

    // 全局清理
    curl_global_cleanup();

    return 0;
}
