﻿========================================================================
    КОНСОЛЬНОЕ ПРИЛОЖЕНИЕ. Обзор проекта Trogalik
========================================================================

Короче паррни, суть проекта, обильно говнокодить, что бы в итоге получить Троллгалилк. Шуточная попытка создать рогалик =)

На повестке дня.

Для реализации управления мышкой.

концепция
при клике мышкой, создается очередь движения, расчитываемая алгоритмом поиска пути.

для героя, прописываем функцию очереди. 
Работает следующим образом.

Каждый такт, работа очереди проверяет не напал ли кто на героя пока он бежит. Если напал, вся очередь сбрасывается.
Нападение на кого либо, так же делает сброс.