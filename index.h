const char indexPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<html>
<head>
  <title>Light Control</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css">
  <script defer src="https://use.fontawesome.com/releases/v5.6.3/js/all.js" integrity="sha384-EIHISlAOj4zgYieurP0SdoiBYfGJKkgWedPHH4jCzpCXLmzVsw1ouK59MuUtP4a1" crossorigin="anonymous"></script>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js"></script>
</head>
<body>
<div class="container pt-5">
  <div class="row">
    <div class="col-md-12">
      <div class="card card-body bg-light text-center">
        <form action="/LED" method="POST">
          <fieldset>
            <legend class="text-center header">Change LED color</legend>
            <div class="form-group row">
              <span class="col-md-1 offset-md-1 text-center col-form-label" style="color: Red;"><i class="far fa-lightbulb"></i></span>
              <div class="col-md-8">
                <input type="number" class="form-control" id="red" name="red" placeholder="Red" value="255">
              </div>
            </div>
            <div class="form-group row">
              <span class="col-md-1 offset-md-1 text-center col-form-label" style="color: Green;"><i class="far fa-lightbulb"></i></span>
              <div class="col-md-8">
                <input type="number" class="form-control" id="green" name="green" placeholder="Green" value="255">
               </div>
            </div>
            <div class="form-group row">
              <span class="col-md-1 offset-md-1 text-center col-form-label" style="color: Blue;"><i class="far fa-lightbulb"></i></span>
              <div class="col-md-8">
                <input type="number" class="form-control" id="blue" name="blue" placeholder="Blue" value="255">
              </div>
            </div>
            <button type="submit" class="btn btn-primary btn-lg">Change LED</button>
          </fieldset>
        </form>
      </div>
    </div>
  </div>
</div>
</body>
</html>
)=====";
