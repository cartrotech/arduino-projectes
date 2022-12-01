//Funcions Basiques Servo

/*-----------------------
 *        Peus
-------------------------*/
 
void AlcaPeuE (byte ang, byte v)
{  
  for (int i=0; i<=ang; i+=5)
  {
    PeuE.write(PEcentre-i);
    PeuD.write(PDcentre-i);
    delay(v);
  }
}

void BaixaPeuE (byte ang, byte v)
{
  for (int i=ang; i>0; i-=5)
  {
    PeuE.write(PEcentre-i);
    PeuD.write(PDcentre-i);
    delay(v);
  }
}

void AlcaPeuD (byte ang, byte v)
{  
  for (int i=0; i<=ang; i+=5)
  {
    PeuE.write(PEcentre+i);
    PeuD.write(PDcentre+i);
    delay(v);
  }
}

void BaixaPeuD (byte ang, byte v)
{
  for (int i=ang; i>0; i-=5)
  {
    PeuE.write(PEcentre+i);
    PeuD.write(PDcentre+i);
    delay(v);
  }
}

/*-----------------------
 *        Cames
------------------------- */
 
void AvantCamaE (byte ang, byte v)
{
  for (int i=0; i<=ang; i+=5)
  {
    CamaE.write(CEcentre-i);
    CamaD.write(CDcentre-i);
    delay(v);
  }
}

void CentraCamaE (byte ang, byte v)
{
  for (int i=ang; i>0; i-=5)
  {
    CamaE.write(CEcentre-i);
    CamaD.write(CDcentre-i);
    delay(v);
  }
}

void ReculaCamaE (byte ang, byte v)
{
  for (int i=0; i<=ang; i+=5)
  {
    CamaE.write(CEcentre+i);
    CamaD.write(CDcentre+i);
    delay(v);
  }
}

void CentraRCamaE (byte ang, byte v)
{
  for (int i=ang; i>0; i-=5)
  {
    CamaE.write(CEcentre+i);
    CamaD.write(CDcentre+i);
    delay(v);
  }
}

void AvantCamaD (byte ang, byte v)
{
  for (byte i=0; i<=ang; i=i+5)
  {
    CamaE.write(CEcentre+i);
    CamaD.write(CDcentre+i);
    delay(v);
  }
}

void CentraCamaD (byte ang, byte v)
{
  for (byte i=ang; i>0; i=i-5)
  {
    CamaE.write(CEcentre+i);
    CamaD.write(CDcentre+i);
    delay(v);
  }
}

void ReculaCamaD (byte ang, byte v)
{
  for (byte i=0; i<=ang; i=i+5)
  {
    CamaE.write(CEcentre-i);
    CamaD.write(CDcentre-i);
    delay(v);
  }
}

void CentraRCamaD (byte ang, byte v)
{
  for (byte i=ang; i>0; i=i-5)
  {
    CamaE.write(CEcentre-i);
    CamaD.write(CDcentre-i);
    delay(v);
  }
}

void DinsCamaDreta(byte ang, byte v)
{
  for (int i=0; i<=ang; i+=5){
    CamaD.write(CDcentre-i);
    delay(v);
  }
}

void CentraDinsCamaDreta(byte ang, byte v)
{
  for (int i=ang; i>0; i-=5){
    CamaD.write(CDcentre-i);
    delay(v);
  }
}

void ForaCamaDreta(byte ang, byte v)
{
  for (int i=0; i<=ang; i+=5){
    CamaD.write(CDcentre+i);
    delay(v);
  }
}

void CentraForaCamaDreta(byte ang, byte v)
{
  for (int i=ang; i>0; i-=5){
    CamaD.write(CDcentre+i);
    delay(v);
  }
}

void DinsCamaEsquerra(byte ang, byte v)
{
  for (byte i=0; i<=ang; i=i+5){
    CamaE.write(CEcentre+i);
    delay(v);
  }
}

void CentraDinsCamaEsquerra(byte ang, byte v)
{
  for (byte i=ang; i>0; i=i-5){
    CamaE.write(CEcentre+i);
    delay(v);
  }
}

void ForaCamaEsquerra(byte ang, byte v)
{
  for (byte i=0; i<=ang; i=i+5){
    CamaE.write(CEcentre-i);
    delay(v);
  }
}

void CentraForaCamaEsquerra(byte ang, byte v)
{
  for (byte i=ang; i>0; i=i-5){
    CamaE.write(CEcentre-i);
    delay(v);
  }
}
