Radomir Cech
CEC0144
Tema: Socialni sit

###################################

Tento program je simulaci socialni site. Obsahuje velkou radu trid, ktere mezi sebou ruzne reaguji. Seznam trid a jejich ucel:
	- SNS = hlavni trida socialni site
	- User (Person) = uzivatel
	- Post (Article) = samotny prispevek na socialni siti
	- PrivateMessage = zprava mezi uzivateli
	- Comment = komentar k prispevkum
	- Group = verejna skupina uzivatel
	- dalsi pomocne - Time, Date a UniversalObjectOutput

V prubehu simulace se provadi ruzne ukony, vsechny ukony jsou realne a jejich vysledky se vzdy ukladaji - napr. komentare k prispevkum, pridavani pratel, zpravy mezi uzivateli... V simulaci se provadi tyto ukony:
	- pridavani novych lidi
	- prejmenovavani lidi
	- navazovani pratelstvi mezi uzivateli
	- sledovani lidi
	- vytvareni prispevku
	- komentovani prispevku
	- vytvareni skupin a pripojovani uzivatelu do nich
	- zasilani zprav mezi uzivateli

Po konci simulace je predvedena ukazka nekterych metod programu jako je napr. zobrazeni pratel uzivatele nebo vsech prispevku.
Je take dulezite zminit, ze veskere vysledky (vytvareni prispevku, navazovani pratel) lze vycist jednotlivymi metodami. Vse se uklada do tridy SNS a jinych trid a lze k tomu pristupovat.
Samozrejme se da projekt jeste vylepsit o dalsi metody jako je napr. mazani prispevku apod., ale bohuzel neni dostatek casu. :(

###################################

Cely program jsem zpracoval sam az na hlavickovy soubor "Colours.h", ktery mam se svolenim vypujceny od kamarada a slouzi k obravovani textu pro lepsi orientaci (funguje v Developer Console ve VS).
Je mozne, ze ve Vasem terminale nebudou barvy fungovat, proto zasilam screenshot "screenshot1.png" a "screenshot2.png" jak program ma spravne vypadat. :)