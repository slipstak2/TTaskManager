Предметная
область.

	Система
управления задачами (органайзер) с
модульной системой.

Введение.

	Проект
разделен на главное
приложение, систему  управления модулями
(плагинами) и систему управления задачами
( задачи представлены в древовидном
виде) . Обобщенная схема представлена
на первом рисунке (первые
два файла .png
и .svg).
Каждый
модуль может решает определенную задачу,
к примеру список книг к прочтению, список
покупок
или
модуль
для напоминая об отдыхе глаз через
определенное время (именно
этот модуль я и хочу сделать в первую
очередь).

	Однако,
приложение
и модули будут имеют графический
интерфейс и
требуют использования промышленных
библиотек,
по этому
к ним вернемся
в
3-ей
части курса (думаю буду использовать
Qt,
так как понадобиться как под Linux, так и
под Windows).


Подробнее
рассмотрим систему управления задачами,
второй рисунок (следующие два файла
.png
и .svg)
Каждый
модуль может получить нужное дерево
задач и выполнять работу c  ним. Система
управления задач может получить дерево
задач из различных источников.

P.S.:
Диаграммы создавал с помощью PlantUml