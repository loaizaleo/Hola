# Hola

Macros de **ROOT** (C++) para analizar la **distribución angular de los fotones de rayos X** de una simulación con **GAMOS/Geant4** y calcular cuántos fotones se dirigen a una región específica del espacio.

## Objetivo

A partir de una simulación de una fuente de rayos X:

1. Obtener cómo se reparten los fotones según los ángulos **θ** (polar) y **φ** (azimutal).
2. Ajustar esa distribución con un polinomio.
3. Integrar el ajuste entre dos ángulos para obtener la fracción de fotones que llega a una región dada (por ejemplo, a un detector).

## Lenguaje y tecnologías

- **C++** como macros de [ROOT](https://root.cern/) (CERN).
- Datos de entrada: `xray2.root`, generado por GAMOS, con los histogramas `GmTrackDataHistosUA_GmGammaFilter:FinalDirTheta` y `...:FinalDirPhi`.

## Archivos

| Archivo | Descripción |
|---|---|
| `distTheta.C` | Normaliza la distribución en θ (0 a π) y la dibuja junto con su ajuste de grado 4. |
| `distPhi.C` | Normaliza la distribución en φ (0 a 2π) y la dibuja junto con su ajuste lineal (casi constante, como se espera). |
| `grafico.C` | Usa el ajuste en θ multiplicado por sin θ para obtener la densidad de fotones e integra entre θ = 1,2657 y 1,2891 rad. |

## Uso

Con ROOT instalado y el archivo `xray2.root` en la misma carpeta:

```bash
root -l distTheta.C
root -l distPhi.C
root -l grafico.C   # no necesita xray2.root; imprime la integral
```

## Notas

- El archivo `xray2.root` **no está en el repositorio**; hay que generarlo con la simulación de GAMOS.
- Los coeficientes del ajuste están escritos en el código; si cambia la simulación, hay que recalcularlos.
- Para calcular otra región, cambie `minlim` y `maxlim` en `grafico.C`.
