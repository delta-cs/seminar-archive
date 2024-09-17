# Navigace skladníka – řešení

Jsou definovány číselné konstanty pro jednotlivé směry pohybu robota. Další konstanty určují typy prvky, které se mohou
ve skladu nacházet.
Načtou se všechna vstupní data. 2D pole reprezentující sklad se naplní zadanými prvky. Založí se proměnné pro aktuální
souřadnice robota a také proměnná ukládající jeho aktuální otočení, zpočátku nastavena (dle zadání) na levou stranu. Pak
už přichází `for` cyklus na vykonávání všech příkazů.

Při příkazu k otočení se volá funkce `rotate`, která dostává aktuální natočení robota z proměnné a logickou hodnotu, zda
se robot otáčí po anebo proti směru hodinových ručiček. Podle logické proměnné buď přičte nebo odečte 1. To využívá
zvolených čísel v konstantách: např. při orientaci nahoru (hodnota 1) a rotaci o 90 stupňů posměru ručiček (+1) vyjde 2,
což je konstanta pro natočení vpravo. Na tento výsledek je pak použit operátor `%` (zbytek po dělení), který zajišťuje
správnost při přechodu z orientace dolů (3) po směru ručiček, tedy doleva (0). Protože 3 + 1 vyjde 4, operátor `%` vrátí
zbytek po dělení 4, čili 0, což je správně. Posledním detailem je, že ve směru proti hodinovým ručičkám, tedy odečítání
1, se navíc přičítá 4 (takže se vlastně celkově přičítá 3). Důvodem je, že operátor `%` nemůže mít na levé straně nulu.
Když tedy po odečtení 1 vyjde 0, přičte se 4 a operátor nakonec stejně vrátí správnou 0.

Při pohybu vpřed se volá funkce `moveForward`. V té se podle orientace zvolí příslušný `for` cyklus, který běží od
robota směrem, jakým se má posunout. Když v tomto směru narazí na sloup, může rovnou skončít. Když narazí na krabici,
neprovede nic. Jinak, čili když narazí na volno, posune veškeré prvky (včetně robota) o jedno políčko v kýženém směru.
Nakonec musí ještě na místo, kde se nacházel robot, zapsat hodnotu z konstanty pro volno. Funkce vrací pole o dvou
prvcích – nové souřadnice robota – aby si je hlavní část programu mohla zapamatovat ve svých proměnných. Když pohyb není
možný, vrátí funkce zkrátka stejné souřadnice, jako dostala v parametrech.

Po provedení všech instrukcí se výsledný stav skladu vypíše za pomoci funkce na výstup. To probíhá standardními dvěma
zanořenými `for` cykly, v nichž se podle hodnoty ve 2D poli rozhoduje o vypisovaném znaku.
