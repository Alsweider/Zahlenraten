# Zahlenraten
Dieses Programm errät mit möglichst wenigen Versuchen eine Zahl, die sich zwischen zwei Grenzwerten befindet. 

[Neueste Version herunterladen](https://github.com/Alsweider/Zahlenraten/releases/latest)

![2026-04-12 06_11_30-Zahlenraten](https://github.com/user-attachments/assets/18064cb0-7118-4428-b702-311b252010a4)

# Mathematik
Zum Erraten wird die binäre Suche eingesetzt. Wenn jede zufallsgenerierte Zahl im Suchbereich mit gleicher Wahrscheinlichkeit die Lösung sein kann, minimiert dieser Algorithmus die maximale Anzahl benötigter Versuche. Er funktioniert folgendermaßen:

1. Teile den Suchbereich in zwei Hälften und wähle den Mittelpunkt.
2. Ist die gesuchte Zahl größer, setze die Untergrenze auf "Mittelpunkt + 1". Ist sie kleiner, setze die Obergrenze auf "Mittelpunkt − 1".
3. Schritt 1 und 2 wiederholen sich, bis nur noch eine Zahl übrig bleibt.

Bei gleichverteilten Zufallszahlen zwischen 1 und 100 kann die gesuchte Zahl mit optimaler binärer Suche in 63 von 100 Fällen innerhalb von 6 Versuchen bestimmt werden (63 % Erfolgswahrscheinlichkeit). Spätestens im 7. Vergleichsschritt ist die Zahl sicher bestimmt.
