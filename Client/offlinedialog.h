#pragma once

#include <QDialog>
#include <QList>
#include <QPair>
#include <QString>

namespace Ui {
class OfflineDialog;
}

namespace ppvs {
enum class Rules : int;
class GameSettings;
}

class Settings;

class OfflineDialog : public QDialog {
	Q_OBJECT

public:
	explicit OfflineDialog(ppvs::GameSettings* gameSettings, QWidget* parent = nullptr);
	~OfflineDialog() override;

private slots:
	void updateEnabled(ppvs::Rules rule) const;
	void on_PlayButton_clicked();
	void on_CancelButton_clicked();
	void on_ModeComboBox_currentIndexChanged(int index) const;
	void on_DefaultRulesCheckbox_clicked() const;
	void on_ColorsCheckBox_toggled(bool checked) const;

private:
	Ui::OfflineDialog* ui;
	const QList<QPair<ppvs::Rules, QString>> mModeList;
	ppvs::GameSettings* mGameSettings;
};
