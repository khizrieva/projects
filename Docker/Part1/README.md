## Part 1. Готовый докер



Используя команду `docker pull nginx` возьмем официальный докер образ и выкачаем его

![docker_pull_nginx](./screenshots/docker_pull_nginx.png)

Проверяем наличие докер образа с помощью команды `docker images`

![проверка_наличия_докер_образа](./screenshots/docker_images.png)

Запускаем докер образ через `docker run -d [image_id|repository]`

![запуск_докера](./screenshots/docker_run.png)

Проверить, что образ запустился через `docker ps`

![проверка_запуска](./screenshots/docker_run_check.png)


Посмотреть информацию о контейнере через `docker inspect [container_id|container_name]`

![](./screenshots/docker_inspect.png)

По выводу команды определить и поместить в отчёт размер контейнера, список замапленных портов и ip контейнера

Размер контейнера

![размер](./screenshots/inspect_size.png)

Список портов

![список_портов](./screenshots/inspect_ports.png)

IP контейнера

![я_тебя_по_айпи_вычислю](./screenshots/inspect_ip.png)

Остановить докер образ через `docker stop [container_id|container_name]`

![остановка_докера](./screenshots/docker_stop.png)

Проверить, что образ остановился через `docker ps`

![](./screenshots/docker_stop_check.png)


Запустить докер с замапленными портами 80 и 443 на локальную машину через команду `run`

![](./screenshots/docker_ports.png)

Проверить, что в браузере по адресу localhost:80 доступна стартовая страница nginx

![](./screenshots/localhost_check.png)

Перезапустить докер контейнер через `docker restart [container_id|container_name]`
Проверить любым способом, что контейнер запустился

![](./screenshots/docker_restart_and_check.png)

По обновлению статуса понятно, что докер был перезапущен.