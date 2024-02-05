Ohjelman kuvaus
===============
Yksinkertainen Hangman eli hirsipuu toteutettuna C-kielellä. 

Ohjelma näyttää aluksi kysyttävän sanan pituuden _-merkeillä lisäen jokaisen kirjaimen väliin välimerkin luettavuuden vuoksi.
Sitten ohjelma pyytää pelaajalta kirjainta.

Mikäli kirjain löytyy kysyttävästä sanasta, ohjelma muuttaa kyseisen tai kyseiset _-merkin oikeaksi kirjaimeksi.
Mikäli kirjainta ei löydy, lisätään virheiden määrää yhdellä ja tulostetaan hirsipuun vaihe virheiden määrän mukaisesti.

Sitten aloitetaan uusi kierros kysymällä uusi kirjain.
Kierroksia jatketaan kunnes joko hirsipuu on valmis (10 virhettä) tai pelaaja on saanut kaikki kirjaimet sanasta näkyviin (voitto).

Tuli ongelmia ääkkösten käsittelyssä. Jostain syystä VSCode ei näyttänyt ääkkösiä oikein niin ohjelman ajossa tulee käyttää windowsin omaa terminaalia.
