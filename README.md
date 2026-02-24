# Rover – OJI 2017 (Clasa a X-a)

## Descriere

Avem un caroiaj N x N.  
Roverul pornește din (1,1) și trebuie să ajungă în (N,N).  
Se poate deplasa în 4 direcții: sus, jos, stânga, dreapta.

Fiecare celulă are o valoare A[i][j] (stabilitatea terenului).

Pentru un Rover de greutate G:
- dacă A[i][j] ≥ G → zona este sigură
- dacă A[i][j] < G → zona este periculoasă

Celulele (1,1) și (N,N) nu sunt periculoase.  
Nu se poate vizita aceeași celulă de două ori.

---

## Cerințe

### V = 1
Se dau N și G.  
Determinați numărul minim de zone periculoase traversate.

### V = 2
Se dă N.  
Determinați greutatea maximă G pentru care există un drum fără zone periculoase.

---

## Date de intrare

Fișier: rover.in

V  
N G   (dacă V = 1)  
N     (dacă V = 2)  
urmează N linii cu N valori (matricea A)

---

## Date de ieșire

Fișier: rover.out

- dacă V = 1 → numărul minim de zone periculoase
- dacă V = 2 → greutatea maximă posibilă

---

## Restricții

- 1 ≤ N ≤ 500
- 1 ≤ G ≤ 5000
- 1 ≤ A[i][j] ≤ 10000
- timp limită: 0.5 secunde
- memorie: 64 MB

---
