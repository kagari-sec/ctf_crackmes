# Challenge Name - Category (CTF名:crackmes.one 年:常設）
- Upload:1:06 PM 07/05/2025
- **Category**: Reversing
- **Time**: 約1.5時間
- **Level**: 1
- **Author**: kagari

## 📄 Description
Yes, the C++ source file is executable, nothing new here. What CLI arguments is the source file expecting?
はい、C++のソースファイルは実行可能ファイルです。特に新しい点はありません。ソースファイルはどのようなCLI引数を期待していますか？

Note: Do not compile or modify the source file! Simply execute it like you'd do with any other regular program. However you will need to have g++ installed on your system.
注意：ソースファイルをコンパイルしたり変更したりしないでください！他の通常のプログラムと同じように実行するだけです。ただし、システムにg++がインストールされている必要があります。

comment: You need to find the correct starting argument with the good exe name
コメント：正しい開始引数と適切な実行ファイル名を見つける必要があります。

## 📂 Provided Files
- 6869233eaadb6eeafb398fdb.zip
- main.cpp

## 🌐 Environment
- URL: https://crackmes.one/crackme/6869233eaadb6eeafb398fdb

## 🔍 Solution
1. fileコマンドを使用すると...
   →C source, ISO-8859 text, with very long lines (356)
   →C言語のソースコードの可能性があるテキストファイルを認識される
2. ファイル内のテキストを base64 デコードしたらパスワードチェックがある
3. 実際に bash main.cpp foo bar even_more_secure_password baz で実行したら collect! が出た

## 🤔 Feelings
久しぶりのctfということで、チャッピーとグーグルを駆使して解法を調べた。
最初は自力でやってみようと、まずはfileコマンドで分析した。

そのあと問題文のC++、g++に誘導されて一応コンパイルを試みたが、うまくいかなかった。
チャッピーに聞いてbase64でデコードしてみたら～といわれやってみた。

if [ $# -eq 3 ]; then echo wrong...; exit 0で引数が3つやろ！と早とちりして、
デコードしたパスポートと合わせて3つの引数でやったらうまくいかなかった。
またチャッピーに聞いたら4つの引数でやるんだよ～といわれ、やったら、

「collect!」とコマンド結果が返ってきたので無事とけれてよかった。
これでレベル1のvery easyなので恐ろしいです。
