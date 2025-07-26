#include "offlinedialog.h"
#include "../Puyolib/Game.h"
#include "../Puyolib/GameSettings.h"
#include "common.h"
#include "settings.h"
#include "ui_offlinedialog.h"
#include <QComboBox>

OfflineDialog::OfflineDialog(ppvs::GameSettings* gameSettings, QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::OfflineDialog)
	, mModeList(getModeList())
	, mGameSettings(gameSettings)
{
	Settings& settings = pvsApp->settings();
	ui->setupUi(this);

	GameModeListIterator modeIterator(mModeList);
	while (modeIterator.hasNext()) {
		GameModePair mode = modeIterator.next();
		ui->ModeComboBox->addItem(mode.second, static_cast<int>(mode.first));
	}

	mGameSettings->playMusic = settings.boolean("launcher", "enablemusic", true);
	mGameSettings->playSound = settings.boolean("launcher", "enablesound", true);
	ui->ColorsSpinBox->setEnabled(ui->ColorsCheckBox->checkState() == Qt::Checked);
}

OfflineDialog::~OfflineDialog()
{
	delete ui;
}

void OfflineDialog::on_PlayButton_clicked()
{
	mGameSettings->ruleSetInfo.setRules(static_cast<ppvs::Rules>(ui->ModeComboBox->itemData(ui->ModeComboBox->currentIndex(), Qt::UserRole).toInt()));

	if (ui->ColorsCheckBox->checkState() == Qt::Checked)
		mGameSettings->ruleSetInfo.colors = ui->ColorsSpinBox->value();
	else
		mGameSettings->ruleSetInfo.colors = 0;

	mGameSettings->ruleSetInfo.numPlayers = mGameSettings->ruleSetInfo.ruleSetType == ppvs::Rules::ENDLESS ? 1 : ui->PlayersSpinBox->value();
	mGameSettings->ruleSetInfo.numHumans = mGameSettings->ruleSetInfo.ruleSetType == ppvs::Rules::ENDLESS ? ui->HumanPlayersSpinBox->value() != 0 : ui->HumanPlayersSpinBox->value();
	mGameSettings->startWithCharacterSelect = true;
	mGameSettings->useCpuPlayers = true;
	if(!ui->DefaultRulesCheckbox->isChecked()){
		mGameSettings->ruleSetInfo.marginTime = ui->MarginTimeSpinBox->value();
		mGameSettings->ruleSetInfo.targetPoint = ui->TargetPointsSpinBox->value();
		mGameSettings->ruleSetInfo.requiredChain = ui->RequiredChainSpinBox->value();
		mGameSettings->ruleSetInfo.initialFeverCount = ui->InitialFeverCountSpinBox->value();
		mGameSettings->ruleSetInfo.feverPower = ui->FeverPowerSpinBox->value();
		mGameSettings->ruleSetInfo.puyoToClear = ui->PuyoToClearSpinBox->value();
		mGameSettings->ruleSetInfo.quickDrop = ui->QuickDropCheckBox->isChecked();
	}
	accept();
}

void OfflineDialog::on_CancelButton_clicked()
{
	reject();
}

void OfflineDialog::on_ColorsCheckBox_toggled(bool checked) const
{
	ui->ColorsSpinBox->setEnabled(checked);
}

void OfflineDialog::updateEnabled(const ppvs::Rules rule) const
{
	ui->MarginTimeSpinBox->setValue(192);
	ui->RequiredChainSpinBox->setValue(0);
	ui->PuyoToClearSpinBox->setValue(4);
	ui->InitialFeverCountSpinBox->setValue(0);
	ui->FeverPowerSpinBox->setValue(100);
	ui->QuickDropCheckBox->setChecked(false);

	bool enabled = !ui->DefaultRulesCheckbox->isChecked();
	ui->MarginTimeSpinBox->setEnabled(enabled);
	ui->TargetPointsSpinBox->setEnabled(enabled);
	ui->RequiredChainSpinBox->setEnabled(enabled);
	ui->PuyoToClearSpinBox->setEnabled(enabled);
	ui->InitialFeverCountSpinBox->setEnabled(enabled);
	ui->FeverPowerSpinBox->setEnabled(enabled);
	ui->QuickDropCheckBox->setEnabled(enabled);

	if (!enabled)
		return;
	switch (rule) {
	case ppvs::Rules::TSU:
	case ppvs::Rules::ENDLESS:
		ui->InitialFeverCountSpinBox->setEnabled(false);
		ui->FeverPowerSpinBox->setEnabled(false);
		ui->TargetPointsSpinBox->setValue(70);
		break;
	case ppvs::Rules::FEVER:
		ui->PuyoToClearSpinBox->setEnabled(false);
		ui->TargetPointsSpinBox->setValue(120);
		break;
	case ppvs::Rules::ENDLESSFEVER:
	case ppvs::Rules::ENDLESSFEVERVS:
		ui->PuyoToClearSpinBox->setEnabled(false);
		ui->InitialFeverCountSpinBox->setEnabled(false);
		ui->TargetPointsSpinBox->setValue(120);
		break;
	}
}

void OfflineDialog::on_ModeComboBox_currentIndexChanged(int index) const
{
	updateEnabled(static_cast<ppvs::Rules>(ui->ModeComboBox->itemData(index, Qt::UserRole).toInt()));
}

void OfflineDialog::on_DefaultRulesCheckbox_clicked() const
{
	updateEnabled(static_cast<ppvs::Rules>(ui->ModeComboBox->itemData(ui->ModeComboBox->currentIndex(), Qt::UserRole).toInt()));
}