#ifndef ACCUEIL_H
#define ACCUEIL_H
#include "achat.h"
#include "vente.h"
#include <QMainWindow>
#include "depense.h"
#include "utilisateur.h"
#include "connexion.h"
#include "QMessageBox"
#include"listedepense.h"
#include "listevente.h"
#include"listeachat.h"
#include"modifierachat.h"
#include"modifiervente.h"
#include"modifierdepense.h"
#include"depense1.h"
#include"marchandise.h"
#include"listemarchandise.h"
#include "modifiermarchandise.h"
#include"compteachat.h"
#include"comptevente.h"
#include"comptedepense.h"
#include"comptemarchandise.h"
#include "authen.h"
#include"authen1.h"
#include"authen2.h"
#include"same.h"
#include"redigerrapportachat.h"
#include"redigerrapportdepense.h"
#include"QTreeView"
#include"QFileDialog"
#include"QSplitter"
#include"QFileSystemModel"
#include"listeuser.h"
#include"authen3.h"
#include"benefice.h"
#include"actif.h"
QT_BEGIN_NAMESPACE
namespace Ui { class accueil;
             }
QT_END_NAMESPACE

class accueil : public QMainWindow
{
    Q_OBJECT


public:
    QSqlDatabase db;
    accueil(QWidget *parent = nullptr);
    ~accueil();


private slots:
    void on_actionEnregistrer_une_activite_triggered();

    void on_actionNouvelle_donnee_triggered();

    void on_actionenregistrer_une_depense_triggered();

    void on_actionnew_user_triggered();

    void on_actionexite_triggered();



    void on_activite_clicked();

    void on_activite_2_clicked();

    void on_offrande_clicked();

    void on_login_clicked();

    void on_logout_clicked();



    void on_actionliste_des_depenses_triggered();

    void on_listedepense_clicked();

    void on_actionliste_des_activites_triggered();

    void on_actionliste_des_donnees_triggered();

    void on_listeactivite_clicked();

    void on_listefond_clicked();

    void on_events_clicked();

    void on_actionsuprimer_une_activite_triggered();

    void on_actionmodifier_une_activite_triggered();

    void on_actionmodifier_donnee_triggered();

    void on_actionsuprimer_modifier_triggered();

    void on_actionSupprimer_triggered();

    void on_actionEnregistrer_marchandise_initial_triggered();

    void on_actionMarchandise_triggered();

    void on_actionmodifier_triggered();

    void on_actionCompte_achat_triggered();

    void on_actionCompte_vente_triggered();

    void on_actionCompte_depense_triggered();

    void on_actionCompte_marchandise_triggered();

    void on_pushButton_clicked();

    void on_nomproduit_textChanged(const QString &arg1);

    void on_actionRediger_une_vente_triggered();

    void on_fichedevente_clicked();

    void on_fichededepense_clicked();

    void on_fichedachat_clicked();

    void on_actionopen_Folder_triggered();

    void on_actionUtilisateurs_triggered();

    void on_mois_4_clicked();

    void on_jour_2_clicked();

    void on_anne_2_clicked();

    void on_tout_clicked();

    void on_listeractivite_clicked();

    void on_enregistrer_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_mois_8_clicked();

    void on_jour_6_clicked();

    void on_anne_6_clicked();

    void on_tout_2_clicked();

    void on_listeractivite_2_clicked();

    void on_enregistrer_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_mois_10_clicked();

    void on_jour_8_clicked();

    void on_anne_8_clicked();

    void on_tout_3_clicked();

    void on_pushButton_7_clicked();

    void on_enregistrer_3_clicked();

    void on_listeractivite_3_clicked();

    void on_mois_14_clicked();

    void on_jour_12_clicked();

    void on_anne_12_clicked();

    void on_tout_4_clicked();

    void on_listeractivite_4_clicked();

    void on_enregistrer_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_supprimer_clicked();

    void on_supprimer_3_clicked();

    void on_supprimer_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_tableView_3_activated(const QModelIndex &index);

    void on_toolButton_triggered(QAction *arg1);

    void on_tableView_5_activated(const QModelIndex &index);

    void on_tableView_2_activated(const QModelIndex &index);

    void on_actionActif_triggered();

    void on_actionBenefice_sur_vente_triggered();

    void on_supprimer_5_clicked();

private:
    Ui::accueil *ui;
    achat * Achat;
    vente * Vente;
     utilisateur * Utilisateur;
    connexion * Connexion;
    listedepense * Listedepense;
    listevente * Listevente;
    listeachat * Listeachat;
    modifierachat * Modifierachat;
    modifiervente * Modifiervente;
    modifierdepense * Modifierdepense;
   depense1 * Depense;
marchandise * Marchandise;
listemarchandise * Listemarchandise;
modifiermarchandise * Modifiermarchandise;
compteachat * Compteachat;
comptedepense * Comptedepense;
comptevente * Comptevente;
comptemarchandise * Comptemarchandise;
authen * Authen;
authen1 * Authen1;
authen2 * Authen2;
authen3 * Authen3;
same * Same;
redigerrapportachat * Redigerrapportachat;
redigerrapportdepense * Redigerrapportdepense;
listeuser * Listeuser;
QTreeView  * Treeview=new QTreeView(this);
QSplitter * splitter=new QSplitter(this);
QFileSystemModel *  dirmodel= new QFileSystemModel(this);

actif * Actif;
benefice * Benefice;
};
#endif // ACCUEIL_H
