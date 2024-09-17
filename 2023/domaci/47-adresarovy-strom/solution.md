# Čtení souboru – řešení

Načte se název souboru a vloží se do funkce či třídy určené k manipulaci se soubory. Nejprve se ověří, že soubor
existuje; pakliže ne, program skončí.

Jinak se zavolá funkce `printDirectoryContents`, která přijímá cestu k adresáři a aktuální úroveň zanoření. Z předaného
adresáře získá všechny soubory a složky. Následně je abecedně seřadí. Podle úrovně zanoření vypíše mezery a odrážku. Po
ní název zadaného adresáře a pod něj seznam obsažených souborů. Nakonec pro každou svou podsložku funkce rekurzivně
zavolá sama sebe, vždy s o 1 vyšší úrovní zanoření. Tím dojde k postupnému vypsání celého stromu.
