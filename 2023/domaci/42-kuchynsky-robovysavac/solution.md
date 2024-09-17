# Kuchyňský robovysavač – řešení

Vyvtoří se 2D pole pro uložení celé podlahy, pole znaků pro všechny různé barvy kachliček a také asociativní pole
ukládající program vysavače. To přiřazuje ke každé barvě celé číslo určující směr pohybu (ty jsou pojmenovány
konstantami) na kachličce této barvy. Cyklus tato pole naplní ze vstupu.

Funkce `tryProgram` vyzkouší vykonat předaný program na kuchyňské podlaze a vrátí, zda robot úspěšně dorazil do stanice.
Ve svém těle si vytváří 2D pole logických proměnných. To je stejně velké jako podlaha a značí, na kterých kachličkách
robot už byl. Je to nutné pro detekci smyček – když se robot dostane na kachličku, kde už by, znamená to, že by se znovu
pohyboval po stejné trase donekonečna. V takovém případě (nebo v případě pokusu o překročení hranic podlahy) funkce
vrátí `false`.

Hlavní část programu tuto funkci opakovaně volá se všemi možnými kombinacemi programu vysavače. O generování těchto
kobinací se stará `for` cyklus, který postupně v programu zvyšuje čísla (mění směry pohybu) na jednotlivých barvách.
Když číslo přeroste 3, je obnoveno na 0 a zvýší se číslo na další barvě. Tím dojde k prozkoušení všech možných programů.
Počet úspěšných se udržuje v proměnné a nakonec je vypsán.
