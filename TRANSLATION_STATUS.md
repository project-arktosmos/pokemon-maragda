# Pokemon Maragda - Estat de la Traducció al Català

## Resum General

| Categoria | Progrés | Estat |
|-----------|---------|-------|
| **Noms de Pokémon** | 100% | ✅ Intencionalment en anglès |
| **Noms de Moviments** | 100% | ✅ CORREGIT (2026-01-02) |
| **Descripcions de Moviments** | ~95% | ✅ Ben fet |
| **Noms d'Habilitats** | 100% | ✅ REVISAT (2026-01-02) |
| **Descripcions d'Habilitats** | 100% | ✅ Complet |
| **Descripcions d'Objectes** | ~95% | ✅ Ben fet |
| **Classes d'Entrenadors** | 100% | ✅ Complet |
| **Noms de Natures** | 100% | ✅ Complet |
| **Diàlegs (text/*.inc)** | 100% | ✅ COMPLET (2026-01-02) |
| **Diàlegs (maps/*)** | 100% | ✅ COMPLET (2026-01-03) |
| **Textos UI (src/strings.c)** | 100% | ✅ COMPLET (2026-01-03) |
| **Noms de Fites (landmarks)** | 100% | ✅ COMPLET (2026-01-03) |
| **Crèdits** | 100% | ✅ COMPLET (2026-01-03) |

---

## Fitxers Completament Traduïts

### Dades del joc (src/data/text/)
- ✅ `move_names.h` - Noms de moviments (CORREGIT 2026-01-02)
- ✅ `abilities.h` - Habilitats (noms i descripcions)
- ✅ `trainer_class_names.h` - Classes d'entrenadors
- ✅ `nature_names.h` - Noms de natures
- ✅ `move_descriptions.h` - Descripcions de moviments
- ✅ `item_descriptions.h` - Descripcions d'objectes
- ✅ `gift_ribbon_descriptions.h` - Descripcions de cintes de regal
- ✅ `credits.h` - Crèdits del joc (2026-01-03)

### Codi font (src/)
- ✅ `strings.c` - Textos d'interfície (menús, missatges, etc.) (2026-01-03)
- ✅ `landmark.c` - Noms de fites del mapa regional (2026-01-03)

### Diàlegs principals (data/text/*.inc)
- ✅ `birch_speech.inc` - Discurs inicial del Prof. Bedoll
- ✅ `trainers.inc` - Diàlegs d'entrenadors
- ✅ `contest_strings.inc` - Textos de concursos
- ✅ `pkmn_center_nurse.inc` - Infermera del Centre Pokémon
- ✅ `mart_clerk.inc` - Botiguer
- ✅ `save.inc` - Missatges de guardat
- ✅ `battle_dome.inc` - Textos de Battle Dome
- ✅ `tv.inc` - COMPLET (2992 línies - 2026-01-02)
- ✅ `apprentice.inc` - Diàlegs d'aprenent (ja traduït)
- ✅ `match_call.inc` - Trucades del PokéNav (ja traduït)
- ✅ `mauville_man.inc` - Home de Mauville (traduït 2026-01-02)
- ✅ `frontier_brain.inc` - Cervells de la Frontera (ja traduït)
- ✅ `battle_tent.inc` - Textos de Battle Tent (ja traduït)
- ✅ `secret_base_trainers.inc` - Bases secretes (ja traduït)
- ⚠️ `braille.inc` - Textos en Braille (en anglès - part del puzzle del joc)

### Mapes (data/maps/*/scripts.inc)
- ✅ `LittlerootTown/scripts.inc` - Poble Arrelferma complet

---

## Convencions de Traducció

### Noms Propis
- **Pokémon**: Es mantenen en anglès (BULBASAUR, PIKACHU, etc.)
- **Personatges**: Traduïts (PROF. BEDOLL, no PROF. BIRCH)
- **Llocs**: Traduïts (POBLE ARRELFERMA, no LITTLEROOT TOWN)

### Terminologia Consistent
| Anglès | Català |
|--------|--------|
| Trainer | Entrenador |
| Badge | Medalla |
| Gym | Gimnàs |
| League | Lliga |
| Champion | Campió/Campiona |
| Elite Four | Alt Comandament |
| Move | Moviment |
| Ability | Habilitat |
| Nature | Natura |
| Type | Tipus |
| PP | PP |
| HP | PS |

### Caràcters Especials Catalans
El joc suporta correctament:
- À, à, È, è, É, é, Í, í, Ò, ò, Ó, ó, Ú, ú
- Ç, ç
- L·L, l·l (ela geminada)
- Ü, ü (dièresi)

---

## Com Contribuir

1. Tria un fitxer de la llista "Requereixen Revisió"
2. Cerca textos en castellà o anglès
3. Tradueix al català seguint les convencions
4. Comprova que el text no superi els límits de caràcters
5. Fes commit amb el format: `Traducció: [fitxer] - [descripció breu]`

---

## Històric de Canvis

| Data | Canvi |
|------|-------|
| 2026-01-02 | Anàlisi inicial de l'estat de traducció |
| 2026-01-02 | Correcció de tots els noms de moviments (castellà → català) |
| 2026-01-02 | Revisió dels noms d'habilitats |
| 2026-01-02 | Traducció parcial de data/text/tv.inc (~250 línies) |
| 2026-01-02 | Traducció extensa de data/text/tv.inc (~2140 línies, 71%) |
| 2026-01-02 | Traducció COMPLETA de data/text/tv.inc (2992 línies, 100%) |
| 2026-01-02 | Traducció de data/text/mauville_man.inc (63 línies) |
| 2026-01-02 | Verificació que tots els fitxers data/text/*.inc estan traduïts |
| 2026-01-03 | Traducció de src/strings.c (menús UI, text de baies, PC, Easy Chat) |
| 2026-01-03 | Traducció de src/landmark.c (42 noms de fites del mapa) |
| 2026-01-03 | Traducció de src/data/credits.h (títols de crèdits) |
| 2026-01-03 | Correcció de "He-hello" → "Ho-hola" a data/text/apprentice.inc |
| 2026-01-03 | Verificació completa de tots els fitxers - TRADUCCIÓ COMPLETADA |

