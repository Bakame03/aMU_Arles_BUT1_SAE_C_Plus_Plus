========================================================================
      APPLICATION DE GESTION DE BIBLIOTHÈQUE - README
========================================================================

--- IMPORTANT : PRÉPARATION AVANT LANCEMENT ---
Comme ce projet est livré compressé, il est possible que les dossiers
vides ne soient pas conservés. Avant toute chose, assurez-vous de créer
les dossiers suivants à la racine du projet (là où se trouve main.cpp) :

1. Dossier 'data/'   : contiendra 'db.txt' (sauvegarde automatique)
2. Dossier 'export/' : contiendra 'index.html' (catalogue généré)
3. Dossier 'build/'  : contiendra les fichiers de compilation

Commande rapide pour Linux/Mac : mkdir -p data export build
------------------------------------------------------------------------

DESCRIPTION :
Ce programme permet de gérer un catalogue de livres. Il offre des 
fonctionnalités d'ajout manuel, d'importation massive via fichiers CSV, 
de recherche, de navigation avec pagination et d'exportation en HTML.

STRUCTURE DU PROJET :
- include/ : Fichiers d'en-tête (.hpp)
- src/     : Fichiers sources (.cpp)
- build/   : Fichiers objets (.o) et exécutable (généré)
- data/    : Fichier de sauvegarde (db.txt)
- import/  : Dossier pour les fichiers CSV à importer
- export/  : Dossier pour les catalogues HTML générés
- Makefile : Script de compilation automatisée

PRÉREQUIS :
- Un compilateur G++ 
- L'outil 'make'

COMPILATION :
1. Ouvrez un terminal dans le dossier racine du projet.
2. Tapez la commande suivante :
   make

L'exécutable 'GestionBiblio' sera créé dans le dossier 'build/'.

UTILISATION :
1. Lancez le programme avec :
   ./build/GestionBiblio
2. Lors du premier lancement, suivez les instructions pour configurer 
   votre bibliothèque (titre et description).
3. Utilisez les chiffres du menu pour naviguer dans les fonctions.
4. Pour quitter, utilisez l'option 6. Le programme vous proposera de 
   sauvegarder vos données.

MAINTENANCE :
- Pour effacer les fichiers de compilation et réinitialiser la base 
  de données, tapez :
  make clean

========================================================================