# -*- coding: utf-8 -*-
"""IFRT-2 — Gerador de traducoes ES/FR/DE/IT em lote."""

import json
import sys
from pathlib import Path

sys.stdout.reconfigure(encoding='utf-8')

input_path = Path(r'C:\Users\wande\Documents\ffx-editor-main\work\_i18n_translate_input.json')
glossary_path = Path(r'C:\Users\wande\Documents\ffx-editor-main\work\_i18n_glossary.json')

with open(input_path, 'r', encoding='utf-8') as f:
    all_keys = json.load(f)

with open(glossary_path, 'r', encoding='utf-8') as f:
    glossary = json.load(f)['oficial']

print(f"Total chaves: {len(all_keys)}")
print(f"Glossario oficial: {len(glossary)} termos")

# Termos UI comuns
ui_terms = {
    "Save": {"es": "Guardar", "fr": "Sauvegarder", "de": "Speichern", "it": "Salva"},
    "Load": {"es": "Cargar", "fr": "Charger", "de": "Laden", "it": "Carica"},
    "Open": {"es": "Abrir", "fr": "Ouvrir", "de": "Öffnen", "it": "Apri"},
    "Close": {"es": "Cerrar", "fr": "Fermer", "de": "Schließen", "it": "Chiudi"},
    "Apply": {"es": "Aplicar", "fr": "Appliquer", "de": "Anwenden", "it": "Applica"},
    "Cancel": {"es": "Cancelar", "fr": "Annuler", "de": "Abbrechen", "it": "Annulla"},
    "Delete": {"es": "Eliminar", "fr": "Supprimer", "de": "Löschen", "it": "Elimina"},
    "Edit": {"es": "Editar", "fr": "Modifier", "de": "Bearbeiten", "it": "Modifica"},
    "View": {"es": "Ver", "fr": "Voir", "de": "Ansehen", "it": "Visualizza"},
    "Filter": {"es": "Filtrar", "fr": "Filtrer", "de": "Filtern", "it": "Filtra"},
    "Search": {"es": "Buscar", "fr": "Rechercher", "de": "Suchen", "it": "Cerca"},
    "Refresh": {"es": "Actualizar", "fr": "Actualiser", "de": "Aktualisieren", "it": "Aggiorna"},
    "Settings": {"es": "Configuración", "fr": "Paramètres", "de": "Einstellungen", "it": "Impostazioni"},
    "Options": {"es": "Opciones", "fr": "Options", "de": "Optionen", "it": "Opzioni"},
    "Enable": {"es": "Activar", "fr": "Activer", "de": "Aktivieren", "it": "Attiva"},
    "Disable": {"es": "Desactivar", "fr": "Désactiver", "de": "Deaktivieren", "it": "Disattiva"},
    "Export": {"es": "Exportar", "fr": "Exporter", "de": "Exportieren", "it": "Esporta"},
    "Import": {"es": "Importar", "fr": "Importer", "de": "Importieren", "it": "Importa"},
    "Preview": {"es": "Vista previa", "fr": "Aperçu", "de": "Vorschau", "it": "Anteprima"},
    "Undo": {"es": "Deshacer", "fr": "Annuler", "de": "Rückgängig", "it": "Annulla"},
    "Redo": {"es": "Rehacer", "fr": "Rétablir", "de": "Wiederherstellen", "it": "Ripeti"},
    "Copy": {"es": "Copiar", "fr": "Copier", "de": "Kopieren", "it": "Copia"},
    "Paste": {"es": "Pegar", "fr": "Coller", "de": "Einfügen", "it": "Incolla"},
    "Cut": {"es": "Cortar", "fr": "Couper", "de": "Ausschneiden", "it": "Taglia"},
    "Select": {"es": "Seleccionar", "fr": "Sélectionner", "de": "Auswählen", "it": "Seleziona"},
    "Add": {"es": "Añadir", "fr": "Ajouter", "de": "Hinzufügen", "it": "Aggiungi"},
    "Remove": {"es": "Eliminar", "fr": "Supprimer", "de": "Entfernen", "it": "Rimuovi"},
    "Clear": {"es": "Limpiar", "fr": "Effacer", "de": "Leeren", "it": "Cancella"},
    "Reset": {"es": "Restablecer", "fr": "Réinitialiser", "de": "Zurücksetzen", "it": "Ripristina"},
    "Confirm": {"es": "Confirmar", "fr": "Confirmer", "de": "Bestätigen", "it": "Conferma"},
    "Warning": {"es": "Advertencia", "fr": "Avertissement", "de": "Warnung", "it": "Avviso"},
    "Error": {"es": "Error", "fr": "Erreur", "de": "Fehler", "it": "Errore"},
    "Success": {"es": "Éxito", "fr": "Succès", "de": "Erfolg", "it": "Successo"},
    "Failed": {"es": "Fallido", "fr": "Échoué", "de": "Fehlgeschlagen", "it": "Fallito"},
    "Loading": {"es": "Cargando", "fr": "Chargement", "de": "Laden", "it": "Caricamento"},
    "Ready": {"es": "Listo", "fr": "Prêt", "de": "Bereit", "it": "Pronto"},
    "Active": {"es": "Activo", "fr": "Actif", "de": "Aktiv", "it": "Attivo"},
    "Inactive": {"es": "Inactivo", "fr": "Inactif", "de": "Inaktiv", "it": "Inattivo"},
}

print(f"Termos UI comuns: {len(ui_terms)}")

def translate_key(key, text, lang):
    for term_en, translations in glossary.items():
        if lang in translations:
            term_target = translations[lang]
            if term_en in text:
                text = text.replace(term_en, term_target)
    for term_en, translations in ui_terms.items():
        if lang in translations:
            term_target = translations[lang]
            if term_en in text:
                text = text.replace(term_en, term_target)
    return text

for lang in ['es', 'fr', 'de', 'it']:
    print(f"\n=== Gerando {lang.upper()} ===")
    translations = {}
    for key, text_en in all_keys.items():
        tr = translate_key(key, text_en, lang)
        translations[key] = tr
    output_path = Path(f'C:\\Users\\wande\\Documents\\ffx-editor-main\\work\\_i18n_tr_{lang}_auto.py')
    with open(output_path, 'w', encoding='utf-8') as f:
        f.write(f'# -*- coding: utf-8 -*-\n')
        f.write(f'"""IFRT-2 — Traducoes {lang.upper()} geradas automaticamente."""\n')
        f.write(f'TR = {{\n')
        for key, tr in translations.items():
            tr_escaped = tr.replace('"', '\\"')
            f.write(f'    "{key}": "{tr_escaped}",\n')
        f.write(f'}}\n')
    print(f"✓ Gerado {output_path.name} com {len(translations)} traducoes")

print("\n✓ Todas as traducoes geradas!")