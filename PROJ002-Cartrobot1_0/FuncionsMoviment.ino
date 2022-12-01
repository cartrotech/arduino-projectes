// Funcions moviment

void Endavant(byte Passos, byte Vel)
{
  Serial.println("Inici endavant");
  ActivaServos();
  AlcaPeuD(iAngle,Vel);
  for (byte j=0; j<Passos; ++j)
  {
    AvantCamaD(bAngle,Vel);
    BaixaPeuD(iAngle,Vel);
    AlcaPeuE(iAngle,Vel);
    CentraCamaD(bAngle,Vel);
    AvantCamaE(bAngle,Vel);
    BaixaPeuE(iAngle,Vel);
    AlcaPeuD(iAngle,Vel);
    CentraCamaE(bAngle,Vel);  
  }
  BaixaPeuD(iAngle,Vel);
  DesactivaServos(); 
  Serial.println("Fi endavant");
}

void Recula(byte Passos, byte Vel)
{
  Serial.println("Inici recula");
  ActivaServos();
  AlcaPeuD(iAngle,Vel);
  for (byte j=0; j<Passos; ++j)
  {
    ReculaCamaD(bAngle,Vel);
    BaixaPeuD(iAngle,Vel);
    AlcaPeuE(iAngle,Vel);
    CentraRCamaD(bAngle,Vel);
    ReculaCamaE(bAngle,Vel);
    BaixaPeuE(iAngle,Vel);
    AlcaPeuD(iAngle,Vel);
    CentraRCamaE(bAngle,Vel);  
  }
  BaixaPeuD(iAngle,Vel);
  DesactivaServos(); 
  Serial.println("Fi recula");
}

void GiraDreta(byte Passos, byte Vel)
{
  Serial.println("Inici gira");
  ActivaServos();
  AlcaPeuD(iAngle,Vel);
  for (byte j=0; j<Passos; ++j)
  {
    ForaCamaDreta(gAngle,Vel);
    BaixaPeuD(iAngle,Vel);
    AlcaPeuE(iAngle,Vel);
    delay(20);
    CentraForaCamaDreta(gAngle,Vel);
    DinsCamaDreta(gAngle,Vel);
    BaixaPeuE(iAngle,Vel);
    AlcaPeuD(iAngle,Vel);
    delay(20);
    CentraDinsCamaDreta(gAngle,Vel);
  }
  BaixaPeuD(iAngle,Vel);
  DesactivaServos();
  Serial.println("Fi gira");
}

void GiraEsquerra(byte Passos, byte Vel)
{
  ActivaServos();
  AlcaPeuE(iAngle,Vel);
  for (byte j=0; j<Passos; ++j)
  {
    ForaCamaEsquerra(gAngle,Vel);
    BaixaPeuE(iAngle,Vel);
    AlcaPeuD(iAngle,Vel);
    delay(20);
    CentraForaCamaEsquerra(gAngle,Vel);
    DinsCamaEsquerra(gAngle,Vel);
    BaixaPeuD(iAngle,Vel);
    AlcaPeuE(iAngle,Vel);
    delay(20);
    CentraDinsCamaEsquerra(gAngle,Vel);
  }
  BaixaPeuE(iAngle,Vel);
  DesactivaServos();
}
