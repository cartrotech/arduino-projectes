void Endavant(byte Passos, byte Vel)
{
  InclinaDretaAmunt (iAngle, Vel);
  for (byte j=0; j<Passos; ++j)
  {
    AvantPeuEsquerra (bAngle, Vel);
    InclinaDretaAvall (iAngle, Vel);
    InclinaEsquerraAmunt (iAngle, Vel);
    CentraPeuEsquerra (bAngle, Vel);
    AvantPeuDreta (bAngle, Vel);
    InclinaEsquerraAvall (iAngle, Vel);
    InclinaDretaAmunt (iAngle, Vel);
    CentraPeuDreta (bAngle, Vel);
  }
  InclinaDretaAvall (iAngle, Vel);
}
