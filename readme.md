# 過程
## 1. 使用clang做parsing

```
clang -S -emit-llvm hello.c -o fill.ll
```
- 可以將hello.c 轉成llvm ir(intermediate representation)

## 2. 用llvm-tool **Dot (graph Description language)** 將 file.ll 做optimization
```
opt -dot-cfg file.ll -disable-output
```
- 會生成一個檔案叫.main.dot 這個檔案為digraph描述檔 可用macos-tool graphviz視覺化，基本上就是一個流程圖。

## 3. 用llvm-tool llc 將IR 轉為 target assembly code
* target 可以為
    * x86
    * arm
    * mips
    * etc
```
llc file.ll --march=x86 -o file.x86
```
- 其中march唸作 **m arch**



# The LLVM Intermediate Representation
## 1. 使用-Xclang -disable-O0-optnone來禁用函數優化，因為想要在opt時才做優化。
```
clang -Xclang -disable-O0-optnone -S -emit-llvm file.c -o file.ll
```
## 2. 優化
```
opt -S -mem2reg f.ll -o f opt.ll
```
其中mem2reg意思是將memory中的數值放到register中，如此一來數值在passing時會比較快

## 3. 結論
我有試過如果在clang時沒有加入-Xclang -disable-O0-optnone，則opt在mem2reg時會沒有用處

# Program Visualization using LLVM
## 1. 在ubuntu安裝 **graphviz**
```
sudo apt install graphviz
```
## 2. 視覺化
-
    ```
    clang -S -emit-llvm file.c -o file.ll
    ```
-
    ```
    dot -Tpdf .test.dot -o test.pdf
    ```
    這行會將.test.dot這個graph description轉成pdf，如下
    ![alt text](./source/ll.png "Title")





