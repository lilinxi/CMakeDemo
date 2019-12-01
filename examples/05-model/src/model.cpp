/**
 * 通过 curl 取回 http://www.linux-ren.org 的首页并写入 /tmp/curl-test 文件中。
 */

#include <curl/curl.h>
#include <cstdio>

FILE *fp;

int write_data(void *ptr, size_t size, size_t nitems, void *stream) {
    int written = fwrite(ptr, size, nitems, (FILE *) fp);
    return written;
}

int main() {
    const char *path = "/tmp/curl-test";
    const char *mode = "w";
    fp = fopen(path, mode);
    curl_global_init(CURL_GLOBAL_ALL);
    CURLcode res;
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.linux-ren.org");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
}
