void InclinaDretaAmunt (byte ang, byte v)
{  
  for (int i=0; i<=ang; i+=5)
  {
    PeuE.write(PEcentre-i);
    PeuD.write(PDcentre-i);
    delay(v);
  }
}

void InclinaDretaAvall (byte ang, byte v)
{
  for (int i=ang; i>0; i-=5)
  {
    PeuE.write(PEcentre-i);
    PeuD.write(PDcentre-i);
    delay(v);
  }
}

void InclinaEsquerraAmunt (byte ang, byte v
{  
  for (int i=0; i<=ang; i+=5)
  {
    PeuE.write(PEcentre+i);
    PeuD.write(PDcentre+i);
    delay(v);
  }
}

void InclinaEsquerraAvall (byte ang, byte v)
{
  for (int i=ang; i>0; i-=5)
  {
    PeuE.write(PEcentre+i);
    PeuD.write(PDcentre+i);
    delay(v);
  }
}

void AvantPeuEsquerra (byte ang, byte v)
{
  for (int i=0; i<=ang; i+=5)
  {
    CamaE.write(CEcentre-i);
    CamaD.write(CDcentre-i);
    delay(v);
  }
}

void CentraPeuEsquerra (byte ang, byte v)
{
  for (int i=ang; i>0; i-=5)
  {
    CamaE.write(CEcentre-i);
    CamaD.write(CDcentre-i);
    delay(v);
  }
}

void AvantPeuDreta (byte ang, byte v)
{
  for (byte i=0; i<=ang; i=i+5)
  {
    CamaE.write(CEcentre+i);
    CamaD.write(CDcentre+i);
    delay(v);
  }
}

void CentraPeuDreta (byte ang, byte v)
{
  for (byte i=ang; i>0; i=i-5)
  {
    CamaE.write(CEcentre+i);
    CamaD.write(CDcentre+i);
    delay(v);
  }
}





void ProvaInclinacio()
{
  for (int i=0; i<=iAngle; i+=5)
  {
    PeuD.write(PDcentre - i);
    PeuE.write(PEcentre - i);    
    delay(50);
  }

  for (int j=iAngle; j>=0; j-=5)
  {
    PeuE.write(PEcentre - j);
    PeuD.write(PEcentre - j);
    delay(50);
  }

  for (int i=0; i<=iAngle; i+=5)
  {
    PeuD.write(PDcentre + i);
    PeuE.write(PEcentre + i);    
    delay(50);
  }

  for (int j=iAngle; j>=0; j-=5)
  {
    PeuE.write(PEcentre + j);
    PeuD.write(PEcentre + j);
    delay(50);
  }  
}
