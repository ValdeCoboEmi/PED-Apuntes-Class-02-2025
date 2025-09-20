# GitFlow
---

## Inicializar GitFlow

Al clonar un repositorio y querer trabajar con GitFlow, primero debemos inicializarlo:

```bash
git flow init
````

Se te pedirá configurar los nombres de las ramas. Puedes aceptar los valores por defecto:

* `master` → producción
* `develop` → desarrollo
* Ramas de características → `feature/`
* Ramas de lanzamientos → `release/`
* Ramas de correcciones → `hotfix/`

---

## Crear una nueva funcionalidad

Para añadir una nueva funcionalidad, usamos:

```bash
git flow feature start matriz-excel
```

Esto:

* Crea la nueva rama a partir de `develop`.
* Te posiciona en la rama `feature/matriz-excel`.

Luego, se hace el flujo normal de Git:

```bash
git add .
git commit -m "Añadida funcionalidad de cuadrícula"
```

Para publicar la rama en el repositorio remoto:

```bash
git flow feature publish matriz-excel
```

Cuando la funcionalidad esté lista y probada:

```bash
git flow feature finish matriz-excel
```

Esto:

* Fusiona la rama de la característica con `develop`.
* Te posiciona en `develop`.

Finalmente, subimos `develop` al repositorio remoto:

```bash
git push origin develop
```

---

## Crear una release

Cuando se tiene una versión estable del código, se realiza una **release**, que normalmente fusiona `develop` con `main`.

Crear la rama de lanzamiento:

```bash
git flow release start v1.0.0
```

En esta rama se pueden hacer cambios finales con los comandos usuales de Git:

```bash
git add .
git commit -m "Preparación para la versión 1.0.0"
```

Finalizar la release:

```bash
git flow release finish v1.0.0
```

Esto:

* Fusiona `release/v1.0.0` en `master`.
* Etiqueta la versión.
* Fusiona los cambios en `develop`.
* Elimina la rama `release/v1.0.0`.

Para reflejar los cambios en el repositorio remoto:

```bash
git push origin main
git push origin develop
```

---

**Notas:**

* Cada tipo de rama (`feature`, `release`, `hotfix`) tiene su propósito dentro del flujo de GitFlow.
* GitFlow automatiza fusiones y etiquetados, reduciendo errores humanos.

