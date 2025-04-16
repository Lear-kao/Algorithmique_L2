---

## 🌳 **1. Arbres binaires – Définitions générales**

### ✅ Définition :
Un **arbre binaire** est un arbre dans lequel **chaque nœud a au plus deux enfants** :
- **Enfant gauche**
- **Enfant droit**

### 🧩 Propriétés :
- Un arbre binaire peut être :
  - **Vide**
  - Ou composé d’un nœud (valeur) + un sous-arbre gauche + un sous-arbre droit
- La **hauteur** est le nombre de niveaux (profondeur maximale)
- Un **nœud feuille** est un nœud sans enfants

---

## 🧱 **2. Types d’arbres binaires particuliers**

| Type                      | Caractéristique principale                                           |
|---------------------------|----------------------------------------------------------------------|
| Arbre binaire complet     | Tous les niveaux sont remplis sauf peut-être le dernier (gauche à droite) |
| Arbre binaire parfait     | Tous les niveaux sont **totalement remplis**                        |
| Arbre binaire plein       | Chaque nœud a **0 ou 2 enfants**                                    |
| Arbre binaire de recherche (ABR / BST) | Sous-arbre gauche < racine < sous-arbre droit (ordre croissant)        |

---

## 🔁 **3. Parcours d’un arbre binaire**

Les **parcours DFS** sont les plus utilisés. Ils s’expriment récursivement.

---

### **3.1 Préordre (Root – Left – Right)**
- Visiter le nœud
- Parcourir le sous-arbre gauche
- Parcourir le sous-arbre droit

**Algorithme :**
```
Visiter(nœud)
Visiter(nœud.gauche)
Visiter(nœud.droit)
```

---

### **3.2 Inordre (Left – Root – Right)**  
- Parcourir le sous-arbre gauche
- Visiter le nœud
- Parcourir le sous-arbre droit

🔹 **Très utilisé pour les arbres binaires de recherche (ABR)** : produit un tri **croissant**

**Algorithme :**
```
Visiter(nœud.gauche)
Visiter(nœud)
Visiter(nœud.droit)
```

---

### **3.3 Postordre (Left – Right – Root)**
- Parcourir le sous-arbre gauche
- Parcourir le sous-arbre droit
- Visiter le nœud

**Algorithme :**
```
Visiter(nœud.gauche)
Visiter(nœud.droit)
Visiter(nœud)
```

---

### **3.4 Parcours en largeur (BFS)**
- Niveau par niveau (de gauche à droite)
- Utilise une **file**

**Algorithme :**
```
Créer une file
Enfiler la racine
Tant que la file n’est pas vide :
    Défile le nœud courant
    Visite le nœud
    Enfile son enfant gauche (s’il existe)
    Enfile son enfant droit (s’il existe)
```

---

## 🧠 **4. Traitements logiques classiques**

### 🧮 A. Calcul de la hauteur
```
Si nœud vide → -1
Sinon → 1 + max(hauteur(gauche), hauteur(droit))
```

---

### 🔢 B. Comptage du nombre de nœuds
```
Si nœud vide → 0
Sinon → 1 + nombre(gauche) + nombre(droit)
```

---

### 🍃 C. Comptage du nombre de feuilles
```
Si nœud est feuille → 1
Sinon → somme des feuilles des deux sous-arbres
```

---

### 🔍 D. Recherche (dans un ABR)
- Si valeur cherchée < racine → aller à gauche
- Si > racine → aller à droite
- Sinon trouvé

---

### ➕ E. Insertion (dans un ABR)
- Même logique que la recherche : insérer à gauche si plus petit, à droite si plus grand

---

### 🗑️ F. Suppression (dans un ABR)
3 cas :
1. Le nœud est une **feuille** → on le supprime
2. Le nœud a **un seul enfant** → on le remplace par son enfant
3. Le nœud a **deux enfants** → on remplace par le successeur ou prédécesseur inordre

---

## 📋 **5. Tableau comparatif des parcours**

| Parcours      | Ordre                   | Utilisation principale                     |
|---------------|--------------------------|---------------------------------------------|
| Préordre      | Racine – Gauche – Droite | Clonage, expression préfixe                 |
| Inordre       | Gauche – Racine – Droite | Tri croissant (pour ABR), expressions infixées |
| Postordre     | Gauche – Droite – Racine | Suppression, expression postfixe            |
| Largeur       | Niveau par niveau        | Algorithmes de plus court chemin, visualisation |

---

Souhaites-tu que je t’en fasse une version visuelle comme pour les arbres quelconques ?