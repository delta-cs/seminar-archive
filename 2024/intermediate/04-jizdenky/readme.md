# Jízdenky

Pan Šetřivý přijel do Prahy na `n` dní a chce používat místní MHD. Zjistil si ceny jednodenních (`j`) a týdenních (`t`) jízdenek. A chce zjistit, která je pro něj výhodnější a tu si pak bude kupovat po celou dobu pobytu (`n`) \
Máš zaručeno že číslo `n` bude dělitelné sedmi. /
Máš zaručeno, že jedna z možností bude levnější.
## Typ vstupu

- `n` - kolik dní chce být v Praze (cele číslo dělitelné sedmi)
- `j` - cena jednoudení jízdenky (cele číslo)
- `t` - cena týdení jízdenky (cele číslo)

## Typ výstupu

na výstupu programu bude:
1. pokud je výhodnější denní tak `denni`
1. pokud je výhodnější týdenní tak `tydenni`

## Příklady

### Příklad 1
#### Vstup
```
14
2
12
```

#### Výstup
```
tydenni
```

#### Vysvětlení
Pokud by si kupoval po dobu 14 dní každý den jízdenku za 2 kč tak by celkem zaplatil `28` kč \
Pokud by si kupoval po dobu 14 dní každý týden jízdenku za 12 kč tak by celkem zaplatil `24` kč \
Takže se mu vyplatí kupovat týdenní jízdenku.
