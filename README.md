# CPP Module 05

Ce module porte sur les exceptions, l'heritage, les classes abstraites et le polymorphisme en C++98.

## Exercices

### ex00 - Bureaucrat

Implementation de la classe `Bureaucrat` avec :

- un nom et un grade compris entre 1 et 150 ;
- les exceptions `GradeTooHighException` et `GradeTooLowException` ;
- l'incrementation et la decrementation du grade ;
- les constructeurs de copie et l'operateur d'affectation.

### ex01 - Form

Ajout de la classe `Form` :

- validation des grades necessaires pour signer et executer un formulaire ;
- signature par un `Bureaucrat` suffisamment gradé ;
- refus de signature lorsque le grade est insuffisant ;
- affichage du resultat de la signature avec `signForm`.

### ex02 - AForm et formulaires concrets

Remplacement de `Form` par la classe abstraite `AForm` et ajout de trois formulaires :

| Formulaire | Grade de signature | Grade d'execution |
| --- | ---: | ---: |
| `ShrubberyCreationForm` | 145 | 137 |
| `RobotomyRequestForm` | 72 | 45 |
| `PresidentialPardonForm` | 25 | 5 |

Chaque formulaire implemente son propre comportement :

- `ShrubberyCreationForm` cree un fichier `<target>_shrubbery` contenant un arbre ASCII ;
- `RobotomyRequestForm` affiche un forage et reussit aleatoirement ;
- `PresidentialPardonForm` affiche que la cible est graciee.

### ex03 - Intern

Ajout de la classe `Intern`, capable de creer dynamiquement un formulaire avec :

```cpp
AForm *form = intern.makeForm("robotomy request", "Bender");
```

Les noms acceptes sont :

- `shrubbery creation` ;
- `robotomy request` ;
- `presidential pardon`.

Un nom inconnu affiche une erreur et retourne `NULL`.

## Compilation

Chaque exercice possede son propre `Makefile` et utilise `c++98` avec les warnings stricts.

Depuis la racine du module :

```sh
make -C ex00
./ex00/Bureaucrat

make -C ex01
./ex01/Bureaucrat

make -C ex02
./ex02/Bureaucrat

make -C ex03
./ex03/Intern
```

Pour nettoyer les fichiers generes :

```sh
make -C ex00 fclean
make -C ex01 fclean
make -C ex02 fclean
make -C ex03 fclean
```

Les commandes `fclean` suppriment les objets, les executables et les fichiers `_shrubbery` produits par les tests.