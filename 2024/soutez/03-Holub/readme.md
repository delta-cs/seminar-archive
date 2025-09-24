<!-- why not compute bandwidth of a homing pigeon? -->
# IPoAC - Ip over avian carriers
Byl jednou jeden Honza...
\
Honza bydlí v odlehlé lokalitě, kde není zrovna dobrý přístup k internetu. To mu až do nedávna tolik nevadilo, avšak jedné hezké neděle večer si vzpoměl, že má do půlnoci odevzdat do školy svůj velký programovací projekt.

Honza se  musí rozhodnout, zda se mu soubory vyplatí poslat přes jeho pomalé internetové připojení pomocí pevné linky, nebo zda bude rychlejší, když pro část souborů sáhne po své tajné zbrani: **RFC 1149** - **IPoAC** - *IP over avian carriers*. (Tento protokol umožňuje posílat packety internetového protokolu pomocí poštovních holubů)
> Holuby jsme si nevymysleli, jedná se o opravdovou specifikaci :). Více na: https://cs.wikipedia.org/wiki/IP_pomoc%C3%AD_po%C5%A1tovn%C3%ADch_holub%C5%AF

---

- Škola je vzdušnou čarou vzdálená `D` m. Holub nese disk o velikosti `C` GB a letí `V` m/s.

- Pevná linka má rychlost přenosu `P` MB/s.

- Honzův projekt se skládá z `N` souborů, všechny mají stejnou velikost - `S` GB. 
    \
    *Soubory jsou nedělitelné (na disk se musí vždy vejít soubor celý, nelze ho rozseknout a druhou část poslat pevnou linkou).*

- Holub je k dispozici pouze 1 a vracet se neumí. \
    *(poslat lze holubem pouze 1 packet, zbytek musí jít pevnou linkou)*
<!-- - Když holub dolédtne do školy, odevzdá disk, otočí se a poletí stále stejnou rychlostí na zpátek. Tam ho může honza opět vyslat s dalšími soubory. -->

**Zjistěte nejkratší dobu (ve vteřinách), za kterou je Honza schopen dostat celý svůj projekt do školy.**

- Výsledek vypište jako celé číslo bez desetinné čárky (není potřeba zaokrouhlovat, pouze odříznout desetinná místa)

### Jednotky
- **1 GB = 1024 MB/s** !

## Vstup
- na jednotlivých řádcích dostanete v tomto pořadí hodnoty:
    - `D` vzdálenost (int)
    - `C` kapacita poštovního holuba (int)
    - `V` rycholost poštovního holuba (int)
    - `P` rycholost pevné linky (float)
    - `N` počet souborů (int)
    - `S` velikost souboru (int)


## Příklady
1)
vstup:
```
10000
10
20
1
10
2
```
výstup:
```
10240
```

2)
vstup:
```
30000
50
5
0.2
10
3
```
výstup:
```
6000
```
