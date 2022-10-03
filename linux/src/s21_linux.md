# Part 1. Установка ОС
## Установить Ubuntu 20.04 Server LTS без графического интерфейса. 

![](./screenshots/part1%20pic1.png)

# Part 2. Создание пользователя
## Создать пользователя, отличного от пользователя, который создавался при установке. Пользователь должен быть добавлен в группу adm

![](/src/screenshots/part2%20pic1.png)

![](/src/screenshots/part2%20pic2.png)

# Part 3. Настройка сети ОС
## Задать название машины вида user-1

![](/src/screenshots/part3%20task1%20pic1.png)
![](/src/screenshots/part3%20task1%20pic2.png)


## Установить временную зону, соответствующую вашему текущему местоположению.

![](/src/screenshots/part3%20task2%20pic1.png)
![](/src/screenshots/part3%20task2%20pic2.png)

## Вывести названия сетевых интерфейсов с помощью консольной команды.

![](/src/screenshots/part3%20task3%20pic1.png)

## Используя консольную команду получить ip адрес устройства, на котором вы работаете, от DHCP сервера.

![](/src/screenshots/part3%20task4%20pic1.png)

## Определить и вывести на экран внешний ip-адрес шлюза (ip) и внутренний IP-адрес шлюза, он же ip-адрес по умолчанию (gw).

![](/src/screenshots/part3%20task5%20pic1.png)
![](/src/screenshots/part3%20task5%20pic2.png)

## Задать статичные (заданные вручную, а не полученные от DHCP сервера) настройки ip, gw, dns (использовать публичный DNS серверы, например 1.1.1.1 или 8.8.8.8).

![](/src/screenshots/Screen%20Shot%202022-07-30%20at%204.32.41%20PM.png)
![](/src/screenshots/changing%20the%20yaml%20file.png)
![](/src/screenshots/Screen%20Shot%202022-07-30%20at%204.29.51%20PM.png)

## Перезагрузить виртуальную машину. Убедиться, что статичные сетевые настройки (ip, gw, dns) соответствуют заданным в предыдущем пункте.

![](/src/screenshots/Screen%20Shot%202022-07-30%20at%204.35.36%20PM.png)
![](/src/screenshots/Screen%20Shot%202022-07-30%20at%204.36.09%20PM.png)

# Part 4. Обновление ОС
## Обновить системные пакеты до последней на момент выполнения задания версии.

![](/src/screenshots/Screen%20Shot%202022-07-30%20at%204.41.05%20PM.png)

# Part 5. Использование команды sudo
## Разрешить пользователю, созданному в Part 2, выполнять команду sudo.

![](/src/screenshots/Screen%20Shot%202022-07-30%20at%205.37.07%20PM.png)
![](/src/screenshots/Screen%20Shot%202022-07-30%20at%205.41.45%20PM.png)
![](/src/screenshots/Screen%20Shot%202022-07-30%20at%205.44.23%20PM.png)

# Part 6. Установка и настройка службы времени
## Настроить службу автоматической синхронизации времени.

![](/src/screenshots/Screen%20Shot%202022-07-30%20at%206.00.14%20PM.png)

# Part 7. Установка и использование текстовых редакторов
## Установить текстовые редакторы VIM (+ любые два по желанию NANO, MCEDIT, JOE и т.д.)

![](/src/screenshots/Screen%20Shot%202022-07-30%20at%206.15.07%20PM.png)

## Используя каждый из трех выбранных редакторов, создайте файл test_X.txt, где X -- название редактора, в котором создан файл. Напишите в нём свой никнейм, закройте файл с сохранением изменений.

![](/src/screenshots/Screen%20Shot%202022-07-31%20at%203.32.40%20PM.png)
![](/src/screenshots/Screen%20Shot%202022-07-31%20at%203.34.44%20PM.png)
![](/src/screenshots/Screen%20Shot%202022-07-31%20at%203.38.00%20PM.png)

![](/src/screenshots/Screen%20Shot%202022-07-31%20at%203.40.09%20PM.png)
![](/src/screenshots/Screen%20Shot%202022-07-31%20at%203.41.23%20PM.png)
![](/src/screenshots/Screen%20Shot%202022-07-31%20at%203.44.00%20PM.png)

редактирование вим поиск и замена\

![](/src/screenshots/Screen%20Shot%202022-07-31%20at%204.16.08%20PM.png)
![](/src/screenshots/Screen%20Shot%202022-07-31%20at%204.16.37%20PM.png)

редактирование joe поиск и замена\

![](/src/screenshots/Screen%20Shot%202022-07-31%20at%204.58.42%20PM.png)
![](/src/screenshots/Screen%20Shot%202022-07-31%20at%204.59.08%20PM.png)
![](/src/screenshots/Screen%20Shot%202022-07-31%20at%205.06.55%20PM.png)

редактирование нано поиск и замена\

![](/src/screenshots/Screen%20Shot%202022-08-02%20at%207.49.44%20PM.png)
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%207.50.04%20PM.png)
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%207.50.28%20PM.png)

# Part 8. Установка и базовая настройка сервиса SSHD
## Установить службу SSHd.

![](/src/screenshots/Screen%20Shot%202022-07-31%20at%205.19.56%20PM.png)


## Добавить автостарт службы при загрузке системы.

![](/src/screenshots/Screen%20Shot%202022-07-31%20at%205.20.48%20PM.png)

## Перенастроить службу SSHd на порт 2022.

![](/src/screenshots/Screen%20Shot%202022-08-02%20at%207.18.46%20PM.png)
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%207.22.08%20PM.png)

## Используя команду ps, показать наличие процесса sshd. Для этого к команде нужно подобрать ключи.

![](/src/screenshots/Screen%20Shot%202022-08-02%20at%207.30.10%20PM.png)

# Перезагрузить систему.

![](/src/screenshots/Screen%20Shot%202022-08-02%20at%207.31.54%20PM.png)

# Part 9. Установка и использование утилит top, htop

## Установить и запустить утилиты top и htop.
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%208.18.31%20PM.png)

1. uptime
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.24.54%20PM.png)
2. количество авторизованных пользователей
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.26.13%20PM.png)
3. общую загрузку системы
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.27.54%20PM.png)
4. общее количество процессов
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.28.56%20PM.png)
5. загрузку cpu
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.30.19%20PM.png)
6. загрузку памяти
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.31.12%20PM.png)
7. pid процесса занимающего больше всего памяти
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.39.26%20PM.png)

PID 804

`shift+M`

8. pid процесса, занимающего больше всего процессорного времени

![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.41.42%20PM.png)

PID 3042

`shift+T`

`control+C`

отсортированному по PID![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.45.16%20PM.png)\
PERCENT_CPU![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.47.10%20PM.png) \
PERCENT_MEM![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.48.25%20PM.png)\
TIME ![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.49.09%20PM.png)
`fn+f6`\
отфильтрованному для процесса sshd
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.51.07%20PM.png)\
`fn+f4`\

с процессом syslog, найденным, используя поиск
с добавленным выводом hostname, clock и uptime
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.52.45%20PM.png)
`fn+f2`\
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.54.28%20PM.png)

# Part 10. Использование утилиты fdisk
## Запустить команду fdisk -l.

![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.58.40%20PM.png)

название жесткого диска - VBOX HARDDISK, его размер - 10 GiB и количество секторов 20971520

размер swap\
![](/src/screenshots/Screen%20Shot%202022-08-02%20at%209.58.40%20PM.png)

# Part 11. Использование утилиты df
## Запустить команду df.
![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2011.39.20%20AM.png)

## Запустить команду df -Th.

![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2011.43.33%20AM.png)

# Part 12. Использование утилиты du

## Запустить команду du.
![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2011.46.55%20AM.png)


## Вывести размер папок /home, /var, /var/log (в байтах, в человекочитаемом виде)

![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2011.54.46%20AM.png)


## Вывести размер всего содержимого в /var/log (не общее, а каждого вложенного элемента, используя *)

![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2011.56.59%20AM.png)

# Part 13. Установка и использование утилиты ncdu

## Установить утилиту ncdu.

![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2012.15.58%20PM.png)

![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2012.35.01%20PM.png)


## Вывести размер папок /home, /var, /var/log.

![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2012.40.49%20PM.png)

![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2012.41.58%20PM.png)

![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2012.42.52%20PM.png)

# Part 14. Работа с системными журналами

Открыть для просмотра:

## 1. /var/log/dmesg

`vim /var/log/dmesg`
![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2012.47.20%20PM.png)

## 2. /var/log/syslog

`vim /var/log/syslog`
![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2012.50.47%20PM.png)

## 3. /var/log/auth.log

`vim /var/log/auth.log`

![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2012.54.28%20PM.png)

Рестарт службы sshd\
![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2012.55.28%20PM.png)

![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2012.57.39%20PM.png)

# Part 15. Использование планировщика заданий CRON

## Используя планировщик заданий, запустите команду uptime через каждые 2 минуты.
`crontab -e`

![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2012.57.39%20PM.png)

![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2012.57.39%20PM.png)

## Удалите все задания из планировщика заданий.

`crontab -r`

![](/src/screenshots/Screen%20Shot%202022-08-03%20at%2012.57.39%20PM.png)
