# Souborový systém – řešení

Funkce `dividePath` přijímá řetězec a rozdělí ho na jednotlivé segmenty cesty. Zároveň když je cesta absolutní, očistí
ji ode všech sekvencí `..`. Cyklem projde všechny segmenty a každý z nich přidá do vytvořeného pole. Když je segment
roven `..`, nepřidá se, ale naopak se poslední přidaný segment odebere, protože se z poslední složky přešlo zpět do její
rodičovské.

Tato funkce se zavolá na obě zadané cesty.

Když je druhá cesta absolutní, vypočítá se nejprve, jak dlouhá je (tj. kolik segmentů má) delší z cest. Tolik průchodů
potom vykoná cyklus. Dokud je ale `i` menší než délky obou cest a zároveň je `i`-tý segment v obou cestách stejný, pak
se průchod přeskočí. Jakmile to ale neplatí, znamená to, že skončila společná část obou cest. Zbytek cesty se tedy musí
zkompletovat jinak. A to tak, že k výsledku nejprve připojí tolik sekvencí `../`, kolik zbývá od `i` do délky první
cesty – tolikrát se totiž bude nutné vrátit do rodičovské složky, než se dojde na společnou část první a druhé cesty.
Potom stačí za výsledek napojit segmenty od `i` do konce druhé cesty. Cyklus pak hned končí.

Když je druhá cesta relativní, projdou se postupně všechny její segmenty přidají se do pole segmentů první cesty. Když
je ale daný segment `..`, nepřidá se, ale naopak se z první cesty odebere poslední (jelikož se z něj přešlo do
rodičovské složky). Kdyby už první cesta neměla žádné segmenty, dojde k přeskočení (z kořenového adresáře se výš přejít
nedá). Všechny (zbylé ze zadání i nově přidané) segmenty první cesty se nakonec přidají do výsledku.
