bool UpdateMainStorage(bool includeCommission, bool triggerReports, bool backupRequired, bool USonly, bool override)
{
  // ...
  return true;
}

bool ReportsNeeded()
{
  return true;
}

struct MainStorageOptions
{
  bool includeCommission=false;
  bool triggerReports=false;
  bool backupRequired=false;
  bool USonly=false;
  bool override=false;

};

bool UpdateMainStorage2(MainStorageOptions opt)
{
  // ... as before but opt.includeCommission instead of just includeCommission, etc ...
  return true;
}


typedef struct sTwoInts 
{
  int one;
  int two;
} TwoInts;

struct ThreeInts
{
  int one;
  int two;
  int three;
};



int main()
{
  bool success = UpdateMainStorage(true, false, ReportsNeeded(), false, true);
  MainStorageOptions mso;
  mso.includeCommission = true;
  mso.triggerReports = ReportsNeeded();
  mso.override = true;
  success = UpdateMainStorage2(mso);

  TwoInts nums2{ 1,2 };
  ThreeInts nums3{ 1,2,3 };

  return 0;
}
