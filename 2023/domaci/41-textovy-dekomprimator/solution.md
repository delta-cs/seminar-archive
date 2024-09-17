# Textový dekomprimátor – řešení

Komprese se vykonává takto: Založí proměnná uchovávající počet opakování aktuálního písmene. Náseldně se text projde
cyklem a pokaždé se ověří, že

- `i` není na posledním indexu v řetězci a zároveň
- písmeno na indexu `i` je stejné jako na `i` + 1.

V takovém případě se může navýšit hodnota v proměnné. Jinak se aktuální písmeno vypíše a za ním (je-li větší než 1)
počet jeho opakování. Proměnnou je také nutné obnovit na 1.

Dekomprese: V průchodu se aktuální písmeno rovnou vypíše. Pak je potřeba zjistit, kolikrát se v řadě opakuje. To
zajišťuje vnořený cyklus, který si v řetězcové proměnné ukládá aktuálně načítané číslo. Když znak na indexu `j` + 1 je
číslice, připojí se na konec této proměnné. Opačný případ znamená, že číslo (označující počet opakování písmene)
skončilo, a tak je proměnná převedena na číslo, a tolikrát je dané písmeno vypsáno. Důležitým krokem je zde nastavení
proměnné vnějšího cyklu `i` na proměnnou vnitřního cyklu `j`, čímž dojde k přeskočení celého načteného čísla. Pokračuje
se tedy až na prvním dalším písmenu.
