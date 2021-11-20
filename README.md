# CompilerBook
## Docker
イメージのビルド

```
docker build -t compilerbook https://www.sigbus.info/compilerbook/Dockerfile
```

テスト実行

```
docker run --rm -it -v $HOME/9cc:/9cc compilerbook
```

シェル起動

```
docker run --rm -it -v $HOME/9cc:/9cc compilerbook
```
