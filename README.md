# Kalk - Progetto di Programmazione ad Oggetti
![Logo](cpp/KalkCpp/UI/Resources/imgs/Built_with_Qt_RGB_logo.png)

### Descrizione

Kalk è stata sviluppata come progetto di Programmazione ad Oggetti, corso del secondo anno presso L'Università di Padova.

Le specifiche di progetto sono disponibili nel file [slidesProgetto.pdf](slidesProgetto.pdf).

### Prerequisiti

Per compilare ed eseguire il codice cpp è richiesto Qt versione 5 o superiore, reperibile da [qui](https://www.qt.io/).
<br/> Per compilare ed eseguire la parte Java, è necessario avere Java versione 1.8 o superiore


### Compilazione ed esecuzione

Per compilare la parte C++ del progetto, è sufficiente eseguire questi due comandi nella cartella /cpp/KalkCpp/

```
qmake
make
```
Finito il make sarà disponibile il file eseguibile da lanciare.

Per compilare la parte Java invece, basterà questo comando nella cartella /Java/src/

```
#Su Windows
javac -cp ";." *.java

#In sistemi Unix-like
javac -cp ":." *.java
```



## Autori
* [ScrappyCocco](https://github.com/ScrappyCocco/) - Model-View-Controller e UI
* [frncscdf](https://github.com/frncscdf) - Parte logica C++ e Java

