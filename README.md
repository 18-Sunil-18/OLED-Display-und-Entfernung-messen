# OLED-Display-und-Entfernung-messen
OLED Display SSD1306 128×64 / 128×32 und Entfernung messen



Link für weitere Infos: https://funduino.de/nr-10-entfernung-messen
                        https://funduino.de/nr-42-oled-display-ssd1306-128x64-128x32



Nr.11 Entfernung messen
Sketch Nr.11: Entfernung messen

Aufgabe: Mit den Ultraschallsensor HC-SR04 und einem Arduino Mikrocontroller soll eine Entfernung gemessen und mit dem „serial-monitor“ angezeigt werden.

Material: Mikrocontroller-Board / Kabel / Breadboard / Hc-SR04 Ultraschallsensor

Wie funktioniert der Ultraschallsensor?

Der Sensor hat vier Anschlüsse: a) 5V(+) b) GND (–) c) echo d) trigger

Die Anschlüsse 5V und GND verstehen sich von selbst, sie versorgen den Sensor mit Energie.

Der Pin „trigger“ bekommt vom Mikrocontroller-Board ein kurzes Signal (5V), wodurch eine Schallwelle vom Ultraschallsensor ausgelöst wird. Sobald die Schallwelle gegen eine Wand oder sonstigen Gegenstand stößt, wird sie reflektiert und kommt irgendwann auch wieder zum Ultraschallsensor zurück. Sobald der Sensor diese zurückgekehrte Schallwelle erkennt, sendet der Sensor auf dem „echo“ Pin ein 5V Signal an das Mikrocontroller-Board. Dieser misst dann lediglich die Zeit zwischen dem Aussenden und der Rückkehr der Schallwelle und rechnet diese Zeit dann in eine Entfernung um. Auf gehts!




Nr. 42 – OLED Display SSD1306 128×64 / 128×32
In dieser Anleitung möchten wir lernen, wie wir ein kleines OLED Display mit 128×64 oder 128×32 Pixeln mit Hilfe eines Arduino Mikrocontrollers ansteuern können.

Material : Arduino Mikrocontroller / Kabel / OLED Display

OLED 128×64 0,96″ (einfarbig)  /  OLED 128×64 0,96″ (gelb / blau)  /  OLED 128×32 0,91″ (einfarbig) /  OLED 128×64 (1,3″) (einfarbig)

OLED Displays haben im Vergleich zu LCD Displays (Liquid Crystal Display – Flüssigkristallanzeige) den Vorteil, dass Sie sehr dünn sind und einen guten Kontrast aufweisen. Daher ist diese Technik in vielen Geräten des Alltags immer häufiger zu finden. Die kleinen OLED Displays im Bereich des Mikrocontrollings sind in der Regel monochrome, also einfarbige, Displays. Die leuchtenden Pixel haben im Vergleich zur Hintergrundfarbe nur eine Farbmöglichkeit. Selbst zweifarbige OLEDs, die wir z.B. in dieser Anleitung verwenden sind monochrom. Im oberen Bereich des Displays (Reihe 1-16) können die Pixel nur gelb und unten (Reihe 17-64) nur blau leuchten.

OLED Displays gibt es in vielen Varianten. Sie unterscheiden sich in Farbe, Größe und auch in der Technik der Ansteuerung. Für diese Anleitung nutzen wir ein Display mit einer Auflösung von 128×64 Pixel und einer Ansteuerung über den I²C Bus (im Deutschen gesprochen als „I-Quadrat-C“). Das OLED Display befindet sich bei diesem Modul auf einer PCB, welches den Treiberchip SSD1306 und die Anschlusspins enthält.

Praxis-tipp: Mit etwas Geschick lässt sich das eigentliche Display von der Träger-PCB trennen, wenn man mit einem Stück Papier zwischen PCB und Glas entlang das dort befindliche doppelseitige Klebeband löst. Dadurch ist das Display nur noch ca. 1mm dick und kann in noch kompakteren Anwendungen eingesetzt werden.

Das Display verfügt über vier Pins:
VCC  – Pin für die Spannungsversorgung, anzuschließen an den 5V Pin des Mikrocontrollers
GND – Ground-Pin, anzuschließen an den GND Pin des Mikrocontrollers
SDA und SCL mit den dafür vorgesehenen Kontakten am Mikrocontroller. Beim UNO R3 gibt es dafür oberhalb des Pin13 einen SDA und SCL Pin. Alternativ können auch die analogen Pins A4 (SDA) und A5 (SCL) verwendet werden.

Für die Programmierung von OLED Displays gibt es viele Möglichkeiten. Zunächst muss überlegt werden, welche Library man verwenden möchte. Alle Libraries haben Vor- und Nachteile. Alle haben die Gemeinsamkeit, dass durch die Installation der Library auch diverse Beispielsketche mitinstalliert werden, die in der Arduinosoftware unmittelbar nach der Installation im Menüpunkt Datei → Beispiele auftauchen. Diese Beispiele geben viele Hinweise auf die Möglichkeiten der Programmierung und zeigen auch grafische Anwendungen auf. Jedoch bringen die vielen Möglichkeiten auch den Nachteil mit sich, dass sehr viel interner Speicher des Mikrocontrollers belegt wird. So gibt es Beispielsketche für OLED Displays, die mehr als 96% des Speicherplatzes (Arduino UNO) nutzen. Für konkrete Operationen wie dem Auswerten von Sensordaten bleibt dann zu wenig Speicherplatz übrig.
Aus diesem Grund befassen wir uns in dieser Anleitung mit einer Bibliothek, die speicheroptimiert und leicht zu bedienen ist. Die Library findet man über den Bibliotheksverwalter unter dem Namen „SSD1306Ascii“.

Um einen ersten Eindruck über die Möglichkeiten zu bekommen, bietet es sich an, zunächst einige Beispielsketche zu testen, die automatisch mit der Installation der Library installiert werden. Ein Sketch heißt „FontSamplesWire“. Man findet ihn in der Arduinosoftware unter dem Menüpunkt Datei → Beispiele → SSD1306Ascii → FontSamplesWire.
Nach dem Hochladen tauchen auf dem OLED Display viele verschiedene Schriftarten auf, die in der Library hinterlegt sind. Auf dem UNO Controller nimmt dieser Sketch 96% des Speicherplatzes ein. Hier wird also auch klar, dass während der regulären Verwendung möglichst wenig verschiedene Schriften verwendet werden sollten.

Die Schriftarten erscheinen bei dem genannten Sketch der Reihe nach auf dem OLED Display.

Ein wesentlich kleinerer Beispielsketch eignet sich gut für die ersten eigenen Programmierungen. Wir öffnen den Sketch „Hello World“ und Datei → Beispiele → SSD1206Ascii → HelloWorldWire und löschen zunächst alles heraus, was nicht zwingend erforderlich ist.

Darüber hinaus gibt es selbst in dieser „kleinen“ Library viele weitere Funktionen, wie zum Beispiel
Seitliches schrollen, dauerhaftes Auf- und Abscrollen, Display um 180° drehen (oled.displayRemap(true);), folgende Textzeile invertieren (oled.setInvertMode(i%2);), gesamtes Display invertieren (oled.invertDisplay(!(i%2));), Buchstabenabstand vergrößern (oled.setLetterSpacing(2);) automatisches Scrollen am Ende des Bildschirms (oled.setScrollMode(SCROLL_MODE_AUTO);) und vieles mehr. Für jede Funktion beinhaltet die Library einzelne Beispielsketche, die im folgenden Bild markiert wurden.


Ausblick
Eine sehr Umfangreiche Library trägt den Namen „U8g2“ und ist in der Lage eine Vielzahl von verfügbaren Displays bzw. Displaycontroller anzusteuern.
Auch die enthaltenen Beispiele sind sehr Umfangreich und geben insbesondere für grafische Anwendungen Hilfestellungen. Um mit der „U8g2“ Library arbeiten zu können, ist es in jedem Beispielsketch notwendig, das richtige Display zu aktivieren. Dafür muss man wissen, über welchen Displaytreiber das verwendete Display verfügt.
In unserem Fall müssen wir von den „auskommentierten“ Displays das folgende durch das entfernen der zwei Schrägstriche „//“ aktivieren:

Bei OLED Displays mit dem SSD1306 Chip:

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

Bei OLED Displays mit dem SH1106 Chip:

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);




Link für weitere Infos: https://funduino.de/nr-10-entfernung-messen
                        https://funduino.de/nr-42-oled-display-ssd1306-128x64-128x32
