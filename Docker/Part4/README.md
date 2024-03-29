## Part 4. Свой докер


Написать свой докер образ, который:

1) собирает исходники мини сервера на FastCgi из Части 3


2) запускает его на 8080 порту

3) копирует внутрь образа написанный ./nginx/nginx.conf


4) запускает nginx.
nginx можно установить внутрь докера самостоятельно, а можно воспользоваться готовым образом с nginx'ом, как базовым.

За основу возьмем 3 часть задания, для этого скопируем конфиг файл и файл с FCGI в директорию *miniserver*

![](./screenshots/nginx_conf_v1.png)

![](./screenshots/hello_world.png)

Далее, напишем Dockerfile и run.sh, все также основываясь на действиях, которые мы проделывали в предыдущей части

![](./screenshots/dockerfile.png)

![](./screenshots/run_sh.png)

После этого все приготовления завершены и теперь с помощью команды `docker build -t miniserver:v1 . ` соберем наш докер образ, при этом указав имя(miniserver) и тег(v1)

![](./screenshots/build_miniserver.png)

Проверяем через `docker images`, что все собралось корректно

![](./screenshots/check_all_OK.png)

Запустить собранный докер образ с маппингом 81 порта на 80 на локальной машине 

![](./screenshots/run_miniserver.png)

Проверить, что по localhost:80 доступна страничка написанного мини сервера

![](./screenshots/localhost_1.png)

![](./screenshots/localhost_2.png)

Дописать в ./nginx/nginx.conf проксирование странички /status, по которой надо отдавать статус сервера nginx

![](./screenshots/nginx_conf_v2.png)

Перезапустить докер образ и проверяем что все работает корректно

![](./screenshots/final.png)