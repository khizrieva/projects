program var1;

uses
  Vcl.Forms,
  chebyshev in 'chebyshev.pas' {Form1},
  Unit2 in 'Unit2.pas' {Form3};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TForm3, Form3);
  Application.Run;
end.
