#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char buffer[256];
    int number;
    float decimal;
    char str[50];

    // 打開輸入檔案以進行讀取
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // 打開輸出檔案以進行寫入
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // 使用 fscanf 讀取資料
    while (fscanf(inputFile, "%d %f %s", &number, &decimal, str) == 3) {
        // 使用 sscanf 解析字串
        char line[256];
        snprintf(line, sizeof(line), "%d %f %s", number, decimal, str);
        sscanf(line, "%d %f %s", &number, &decimal, str);

        // 使用 fwrite 寫入資料
        fwrite(line, sizeof(char), strlen(line), outputFile);
        fwrite("\n", sizeof(char), 1, outputFile);
    }

    // 使用 fseek 和 ftell
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    printf("File size: %ld bytes\n", fileSize);
    fseek(inputFile, 0, SEEK_SET);

    // 使用 fread 和 fseek
    size_t bytesRead = fread(buffer, sizeof(char), sizeof(buffer), inputFile);
    buffer[bytesRead] = '\0';
    printf("Read content: %s\n", buffer);

    // 使用 fgets 和 fputs
    fseek(inputFile, 0, SEEK_SET);
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        fputs(buffer, outputFile);
    }

    // 關閉檔案
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

