#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ajouter.h"
#include "verifier.h"

void on_buttonajouter_clicked(GtkWidget *objet_graphique, gpointer user_data)            
{
  GtkWidget *window2;

GtkWidget* entryNom;
GtkWidget* entryPrenom;
GtkWidget* entryUsername;
GtkWidget* entryPassword;
GtkWidget* entryRole;


char nom[50];
char prenom[50];
char username[50];
char password[50];
int role;

entryNom = lookup_widget(objet_graphique, "entryNom");
entryPrenom = lookup_widget(objet_graphique, "entryPrenom");
entryUsername = lookup_widget(objet_graphique, "entryUsername");
entryPassword = lookup_widget(objet_graphique, "entryPassword");
entryRole = lookup_widget(objet_graphique, "entryRole");

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entryNom)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(entryPrenom)));
strcpy(username,gtk_entry_get_text(GTK_ENTRY(entryUsername)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(entryPassword)));

role = atoi(gtk_entry_get_text(GTK_ENTRY(entryRole)) ) ;

ajouter(nom, prenom, username, password, role);
  window2 = create_window2 ();
  gtk_widget_show (window2);

}


void on_buttonLogin_clicked(GtkWidget *objet_graphique, gpointer user_data) {
    GtkWidget *entryUsernameLogin;
    GtkWidget *entryPassLogin;
    GtkWidget *labelstats;
    GtkWidget *window3;

    char usernameLogin[50];
    char passwordLogin[50];

    entryUsernameLogin = lookup_widget(objet_graphique, "entryUsernameLogin");
    entryPassLogin = lookup_widget(objet_graphique, "entryPassLogin");
    labelstats = lookup_widget(objet_graphique, "labelstats");

    strcpy(usernameLogin, gtk_entry_get_text(GTK_ENTRY(entryUsernameLogin)) );
    strcpy(passwordLogin, gtk_entry_get_text(GTK_ENTRY(entryPassLogin)) );

    if (verifier(usernameLogin, passwordLogin) == 1) {
        window3 = create_window3();
        gtk_widget_show(window3);

    } else {
	gtk_label_set_text(GTK_LABEL(labelstats),"error : User invalid");	

        
    }
}


